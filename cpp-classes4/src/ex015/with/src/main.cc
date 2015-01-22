/* W. H. Bell
** A program to demonstrate the application of polymorphism.
*/

#include <iostream>
#include "BasicParticle.h"
#include "SmearedParticle.h"

using namespace std;

int main() {
  double fourvector1[4] = {3.0, 4.0, 5.0, 7.35};

  BasicParticle *basicParticle = new BasicParticle(fourvector1);
  SmearedParticle *smearedParticle = new SmearedParticle(fourvector1);

  cout << "basicParticle mass = " << basicParticle->getMass() << endl;
  cout << "basicParticle pt = " << basicParticle->getPt() << endl << endl;
  cout << "smearedParticle mass = " << smearedParticle->getMass() << endl;
  cout << "smearedParticle pt = " << smearedParticle->getPt() << endl;

  delete basicParticle;
  delete smearedParticle;

  return 0;
}
