/* W. H. Bell
** A coloured bean bag.
*/

#include "BeanBag.h"

BeanBag::BeanBag(char colour) {
  m_bagColour = colour;
}

int BeanBag::fillWith(int moreBeans) {
  int maxBeans;

  maxBeans = (int)(getVolume()/BEAN_VOLUME);
  if((m_beans+moreBeans) > maxBeans) {
    moreBeans = maxBeans - m_beans;
  }
  
  m_beans+=moreBeans;

  return moreBeans;
}

int BeanBag::removeBeans(int removeBeans) {
  if((m_beans-removeBeans) < 0) {
    removeBeans = m_beans;
  }

  m_beans-=removeBeans;  

  return removeBeans;
}

int BeanBag::getNumBeans(void) {
  return m_beans;
}

