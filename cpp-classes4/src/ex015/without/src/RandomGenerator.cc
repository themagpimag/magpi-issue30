/* W. H. Bell
** A random number generator
*/

#include "RandomGenerator.h"
#include <cmath>
#include <stdlib.h>

#include <iostream>

// true => spare random deviate stored.
bool RandomGenerator::randomGausStatus = false;

/*    Returns a normally distributed deviate with zero mean and
**    unit variance, using rand() as the source of uniform
**    deviates. 
*/
double RandomGenerator::randomGaussian() {
  double rsq = 0, v1 = 0., v2 = 0., fac;
  double randomValue;
  static double spareRandomValue = 0.;

  // If there is a spare random deviate return it.
  if(randomGausStatus) {
    randomGausStatus = false;
    return spareRandomValue;
  }

  // Find two random deviates.
  do {
    v1 = 2.0*((double)rand())/RAND_MAX - 1.0;
    v2 = 2.0*((double)rand())/RAND_MAX - 1.0;
    rsq=std::pow(v1,2)+std::pow(v2,2);  // see if they are in the unit circle,
  } while(rsq > 1.0 || rsq == 0.0);  // and if they are not, try again.

  // -- Now make the Box-Muller transformation to get two normal deviates.
  // -- Return one and save the other for next time.
  fac = std::sqrt (-2.*std::log(rsq)/rsq);
  randomValue = v1 * fac;
  spareRandomValue = v2 * fac;
  randomGausStatus = true; // Set the flag.

  return randomValue;
}
