/* W. H. Bell
** A simple object container.
*/

#ifndef COLOUREDBAG_H
#define COLOUREDBAG_H

// Include the base class.
#include "Bag.h"

// ColouredBag inherits from Bag
class ColouredBag: public Bag {
public:
  ColouredBag(char c='0'): // Set the bag colour
  Bag(),  // Set the volume of the bag to zero
  m_bagColour(c){  // Set the bag colour
  }
  char colour(void) {  // Return the bag colour
    return m_bagColour;
  }
  void setColour(char c) { // Set the bag colour
    m_bagColour = c;
  }

private:
  char m_bagColour; // Variable to store a colour character
};

#endif
