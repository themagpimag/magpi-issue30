/* W. H. Bell
** A simple object container.
*/

#ifndef BEANBAG_H
#define BEANBAG_H

// Include the base class.
#include "ColouredBag.h"

// BeanBag inherits from ColouredBag
class BeanBag: public ColouredBag {
public:
  BeanBag(char colour='0', int beans=0):
    ColouredBag(colour),
    m_beans(0) {
  }
  int beans(void){
    return m_beans;
  }
  void setBeans(int beans){
    m_beans = beans;
  }

private:
  int m_beans;
};

#endif
