#ifndef BEANBAG_H
#define BEANBAG_H

// Include the base class
#include "ColouredBag.h"

// BeanBag inherits from ColouredBag
class BeanBag: public ColouredBag {
public:
  BeanBag(char colour='0', int beans=0): // Constructor with default values
    ColouredBag(colour),  // Set the value of the colour, by calling the constructor
    m_beans(beans) {  // Set the number of beans
  }
  int beans(void){  // Return the number of beans
    return m_beans;
  }
  void setBeans(int beans){ // Set the number of beans
    m_beans = beans;
  }

private:
  int m_beans;  // The number of beans in the bag
};

#endif
