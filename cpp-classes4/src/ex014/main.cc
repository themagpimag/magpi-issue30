/* W. H. Bell
** A program to introduce inheritance.
*/

#include <iostream>
#include "Bag.h"
#include "ColouredBag.h"
#include "BeanBag.h"

using namespace std;

int main() {
  Bag bag(30.0);
  
  ColouredBag colouredBag;
  colouredBag.setVolume(40.0);
  colouredBag.setColour('r');

  BeanBag beanBag('b');
  beanBag.setVolume(50.0);
  beanBag.fillWith(100);

  cout << "Volume of bag = " << bag.getVolume() << endl << endl;
  cout << "Volume of colouredBag = " << colouredBag.getVolume() 
       << endl;
  cout << "Colour of colouredBag = " << colouredBag.getColour() 
       << endl << endl;
  cout << "Volume of BeanBag = " << beanBag.getVolume() 
       << endl;
  cout << "Colour of BeanBag = " << beanBag.getColour() 
       << endl;
  cout << "Beans in BeanBag = " << beanBag.getNumBeans() 
       << endl;

  return 0;
}
