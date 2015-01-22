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
  /** A member function to set the bag colour. */
  void setColour(char);

  /** A member function to get the bag colour. */
  char getColour(void);

protected:
  /** A data member to store the bag colour */
  char m_bagColour;
};

#endif
