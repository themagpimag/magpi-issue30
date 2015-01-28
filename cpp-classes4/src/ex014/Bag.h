#ifndef BAG_H
#define BAG_H

class Bag {
public:
  Bag(double volume=0):  // Constructor, with default value
  m_volume(volume) {
  }

  double volume(void){  // Return volume of bag
    return m_volume;
  }

  void setVolume(double volume){  // Set the volume of the bag 
    m_volume = volume;
  }

private:
  double m_volume; // A data member to store the volume
};

#endif
