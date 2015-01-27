/* W. H. Bell
** A simple object container.
*/

#include "Bag.h"

/** Constructors ********************/
Bag::Bag()
{
  setVolume(1.0);
}

Bag::Bag(double volume)
{
  setVolume(volume);
}

double Bag::getVolume(void) {
  return m_volume;
}

void Bag::setVolume(double volume) {
  m_volume = volume;
}

