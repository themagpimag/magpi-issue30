CC=g++
TARGET=trans
OBJECTS=main.o TwoVector.o MatrixTransform.o

$(TARGET): $(OBJECTS)
	@echo "** Linking Executable"
	$(CC) $(OBJECTS) -o $(TARGET)

clean:
	@rm -f *.o *~

veryclean: clean
	@rm -f $(TARGET)

%.o: %.cpp
	@echo "** Compiling C++ Source" 
	$(CC) -c $(INCFLAGS) $< 
