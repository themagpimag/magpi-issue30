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
  beanBag.setBeans(100);

  cout << "Volume of bag = " << bag.volume() << endl << endl;
  cout << "Volume of colouredBag = " << colouredBag.volume() 
       << endl;
  cout << "Colour of colouredBag = " << colouredBag.colour() 
       << endl << endl;
  cout << "Volume of BeanBag = " << beanBag.volume() 
       << endl;
  cout << "Colour of BeanBag = " << beanBag.colour() 
       << endl;
  cout << "Beans in BeanBag = " << beanBag.beans() 
       << endl;

  return 0;
}
