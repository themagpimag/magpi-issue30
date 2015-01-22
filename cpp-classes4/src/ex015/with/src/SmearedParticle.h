/* W. H. Bell
** A simple representation of a smeared particle.
*/

#ifndef SMEARED_PARTICLE_H
#define SMEARED_PARTICLE_H

// Precompiler definition of the CDF electromagnetic calorimeter resolution.
#define ECAL_RESOLUTION 0.135

// Include the base class
#include "BasicParticle.h"

// Inherit from BasicParticle
class SmearedParticle: public BasicParticle {
public:
  /** The default constructor */
  SmearedParticle(void);

  /** Construct a SmearedParticle with a specific four vector */
  SmearedParticle(double *fourvector);

private:
  /** A function to calculate the particle mass after smearing. */
  virtual void calculateMass();

  /** A function to provide a smeared version of the stored four vector */
  void smear(double *smearedFourVector);
};

#endif
