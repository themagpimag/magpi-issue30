using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using RPi.I2C.Net;

namespace Pi_I2CTest
{
    class Programer
    {
        static I2CBus bus;
        static short AC1, AC2, AC3, B1, B2, MB, MC, MD;
        static ushort AC4, AC5, AC6;
        static int deviceID = 0x77;

        static void Main(string[] args)
        {
            bus = I2CBus.Open("/dev/i2c-1");

            if (!Detect())
            {
                Console.WriteLine("Some error occurred during communication with the sensor. Please check the sensor.");
                Console.ReadLine();
                Environment.Exit(0);
            }

            InitParams();

            for (int i = 0; i < 60; i++)
            {
                Console.WriteLine("Temp: {0} °C,  Pressure: {1:N2} hPa", GetTemperature(), GetPressure());
                System.Threading.Thread.Sleep(1000);
            }

            bus.Dispose(); //very important! Dispose of the I2CBus instance when you're done.
            Console.WriteLine("Done.");

        }

        static bool Detect()
        {
            byte[] results;
            try
            {
                bus.WriteByte(0x77, (byte)0xD0);
                results = bus.ReadBytes(0x77, 1);
                if (results[0] != 0x55) return false;
            }
            catch
            {
                return false;
            }
            return true;
        }

        static void InitParams()
        {
            AC1 = ReadSignedWord(0xAA, 0xAB); //read the specified MSB and LSB addresses and load the content therein into variable AC1
            AC2 = ReadSignedWord(0xAC, 0xAD);
            AC3 = ReadSignedWord(0xAE, 0xAF);
            AC4 = ReadUnsignedWord(0xB0, 0xB1);
            AC5 = ReadUnsignedWord(0xB2, 0xB3);
            AC6 = ReadUnsignedWord(0xB4, 0xB5);
            B1 = ReadSignedWord(0xB6, 0xB7);
            B2 = ReadSignedWord(0xB8, 0xB9);
            MB = ReadSignedWord(0xBA, 0xBB);
            MC = ReadSignedWord(0xBC, 0xBD);
            MD = ReadSignedWord(0xBE, 0xBF);
        }

        static short ReadSignedWord(int msbAddress, int lsbAddress)
        {
            bus.WriteByte(deviceID, (byte)msbAddress); //select the MSB
            byte[] result = bus.ReadBytes(0x77, 1); //read one byte from MSB address
            bus.WriteByte(deviceID, (byte)lsbAddress); //select the LSB
            byte[] result2 = bus.ReadBytes(0x77, 1); //read one byte from LSB address
            short finalValue = (short)(result[0] << 8); //shift the MSB, store it in a 16bit variable
            finalValue |= (short)result2[0]; //OR the MSB with the LSB
            return finalValue;

        }

        static ushort ReadUnsignedWord(int msbAddress, int lsbAddress)
        {
            bus.WriteByte(deviceID, (byte)msbAddress); //read the MSB
            byte[] bytes = bus.ReadBytes(deviceID, 1);
            ushort raw = (ushort)((ushort)bytes[0] << 8);
            bus.WriteByte(deviceID, (byte)lsbAddress); //read the LSB
            bytes = bus.ReadBytes(deviceID, 1);
            raw |= (ushort)bytes[0];
            return raw;
        }

        static double GetTemperature()
        {
            byte[] bytes = new byte[] { 0xF4, 0x2E }; //0xF4 (address), 0x2E (data)
            bus.WriteBytes(deviceID, bytes); //write address, then data
            System.Threading.Thread.Sleep(7); //delay
            ushort ut = ReadUnsignedWord(0xF6, 0xF7); //read raw value from sensor
            long x1 = (long)((ut - AC6) * AC5 / Math.Pow(2, 15)); //calculate x1
            long x2 = (long)(MC * Math.Pow(2, 11) / (x1 + MD)); //calculate x2
            long b5 = x1 + x2; //calculate b5
            long temp = (long)((b5 + 8) / Math.Pow(2, 4)); //calculate temp
            //temp now contains the temperature in 0.1 centigrade steps
            return temp * 0.1;
        }

        static double GetPressure()
        {
            double current_temperature = GetTemperature(); //this is needed to determine the pressure, so get the most recent value
            byte[] bytes = new byte[] { 0xF4, (byte)(0x34 + (3 << 6)) }; //store the address & command sequence
            bus.WriteBytes(deviceID, bytes); //actually write it to the I2c device
            System.Threading.Thread.Sleep(28); //wait for the conversion to complete
            bus.WriteByte(deviceID, (byte)0xF6); //write the address of the MSB
            byte ms = bus.ReadBytes(deviceID, 1)[0]; //read one byte from the device
            bus.WriteByte(deviceID, (byte)0xF7); //write the address of the LSB
            byte ls = bus.ReadBytes(deviceID, 1)[0]; //read one byte from the device
            bus.WriteByte(deviceID, (byte)0xF8); //write the address of the XLSB
            byte xs = bus.ReadBytes(deviceID, 1)[0]; //read one byte from the device

            //this is not the formula used in the datasheet. I had some trouble with that, so I used
            //the implementation in the Sparkfun or Adafruit BMP180 library...I forget which specifically.
            double pu = (ms * 256.0) + ls + (xs / 256.0);
            double s, x, y, z;
            double x0 = AC1;
            double x1 = 160.0 * Math.Pow(2, -13) * AC2;
            double x2 = Math.Pow(160, 2) * Math.Pow(2, -25) * B2;
            double c3 = 160.0 * Math.Pow(2, -15) * AC3;
            double c4 = Math.Pow(10, -3) * Math.Pow(2, -15) * AC4;
            double b1 = Math.Pow(160, 2) * Math.Pow(2, -30) * B1;
            double y0 = c4 * Math.Pow(2, 15);
            double y1 = c4 * c3;
            double y2 = c4 * b1;
            double p0 = (3791.0 - 8.0) / 1600.0;
            double p1 = 1.0 - 7357.0 * Math.Pow(2, -20);
            double p2 = 3038.0 * 100.0 * Math.Pow(2, -36);
            s = current_temperature - 25.0;
            x = (x2 * Math.Pow(s, 2)) + (x1 * s) + x0;
            y = (y2 * Math.Pow(s, 2)) + (y1 * s) + y0;
            z = (pu - x) / y;
            double P = (p2 * Math.Pow(z, 2)) + (p1 * z) + p0;
            return P;
        }
    }
}
