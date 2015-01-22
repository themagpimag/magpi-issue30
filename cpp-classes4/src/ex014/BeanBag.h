/* W. H. Bell
** A simple object container.
*/

#ifndef BEANBAG_H
#define BEANBAG_H

// Include the base class.
#include "ColouredBag.h"

// A precompiler statement to define the bean volume.
#define BEAN_VOLUME 5.4

// BeanBag inherits from ColouredBag
class BeanBag: public ColouredBag {
public:
  /** Constructor specifying the bag colour. */
  BeanBag(char colour);

  /** Add more beans.  The member function returns the number of 
  ** beans which have been added. */
  int fillWith(int );

  /** Remove beans. The member function returns the number of
   ** beans which have been removed. */
  int removeBeans(int );

  /** A function to return the number of beans in the bean bag. */
  int getNumBeans(void);

private:
  /** A data member to store the number of beans. */
  int m_beans;
};

#endif
