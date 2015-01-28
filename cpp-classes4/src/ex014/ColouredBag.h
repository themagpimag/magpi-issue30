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
  ColouredBag(char c='0'):
  m_bagColour(c){
  }
  char colour(void) {
    return m_bagColour;
  }
  void setColour(char c) {
    m_bagColour = c;
  }

protected:
  char m_bagColour;
};

#endif
