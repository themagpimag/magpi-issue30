/* W. H. Bell
** A coloured object container.
*/

#include "ColouredBag.h"

void ColouredBag::setColour(char bagColour) {
  m_bagColour = bagColour;
}

char ColouredBag::getColour(void) {
  return m_bagColour;
}

