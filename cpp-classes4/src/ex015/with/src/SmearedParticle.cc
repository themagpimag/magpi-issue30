/* W. H. Bell
** A simple representation of a smeared particle.
*/

#include "SmearedParticle.h"
#include "RandomGenerator.h"
#include <cmath>
#include <iostream>

using namespace std;

/** Constructors ********************/
SmearedParticle::SmearedParticle() : BasicParticle() {
}

SmearedParticle::SmearedParticle(double *fourvector) {
  assignFourVector(fourvector);
}

/** Private member functions ********/
void SmearedParticle::calculateMass() {
  double msq;
  double smearedFourVector[4];

  smear(smearedFourVector);

  msq = std::pow(smearedFourVector[3],2) - std::pow(smearedFourVector[0],2) - std::pow(smearedFourVector[1],2) - std::pow(smearedFourVector[2],2);

  if(msq<0) {
    cerr << "Error: invalid fourvector.  Mass squared = "
	 << msq << endl;
    m_mass = 0.;
  }
  else {
    m_mass = sqrt(msq);
  }

  std::cout << "Smeared mass calculation." << std::endl;
}

void SmearedParticle::smear(double *smearedFourVector) {
  double pt,sigma,sigmaGen;

  pt = std::sqrt(std::pow(m_fourvector[0],2)+std::pow(m_fourvector[1],2));
  sigma = ECAL_RESOLUTION/std::sqrt(pt);
  sigmaGen = RandomGenerator::randomGaussian()*sigma;

  for(int i=0;i<4;i++)
    smearedFourVector[i] = m_fourvector[i]*(1.0+sigmaGen);
}
