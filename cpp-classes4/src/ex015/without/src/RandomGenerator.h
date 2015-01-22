/* W. H. Bell
** A random number generator
*/

#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

class RandomGenerator {
public:
  /** A member function to keep track of spare deviates. */
  static bool randomGausStatus;

  /** A member function to generate a random number inside a 
  ** normal distribution. */
  static double randomGaussian();
};

#endif
