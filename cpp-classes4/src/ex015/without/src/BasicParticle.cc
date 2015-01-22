/* W. H. Bell
** A simple representation of a particle.
*/

#include "BasicParticle.h"
#include <cmath>
#include <iostream>

using namespace std;

/** Constructors ********************/
BasicParticle::BasicParticle(): m_pt(0.),
                                m_mass(0.) {
  for(int i=0;i<4;i++) m_fourvector[i] = 0.;
}

BasicParticle::BasicParticle(double *fourvector) {
  assignFourVector(fourvector);
}

/** Public member functions *********/
void BasicParticle::assignFourVector(double *fourvector) {
  cout << "Assigning fourvector to particle:" << endl;
  for(int i=0;i<4;i++) {
    m_fourvector[i] = fourvector[i];
    cout << "fourvector[" << i << "]="
	 << fourvector[i] << endl;
  }
  cout << endl;

  calculatePt();
  calculateMass();
}

double BasicParticle::getPt() {
  return m_pt;
}

double BasicParticle::getMass() {
  return m_mass;
}

/** Protected member functions ********/
void BasicParticle::calculatePt() {
  m_pt = std::sqrt(std::pow(m_fourvector[0],2)+std::pow(m_fourvector[1],2));
}

void BasicParticle::calculateMass() {
  double msq;

  msq = std::pow(m_fourvector[3],2) - std::pow(m_fourvector[0],2)
        - std::pow(m_fourvector[1],2) - std::pow(m_fourvector[2],2);

  if(msq<0) {
    cerr << "Error: invalid fourvector.  Mass squared = "
	 << msq << endl;
    m_mass = 0.;
  }
  else {
    m_mass = std::sqrt(msq);
  }
}

void BasicParticle::getFourVector(double *fourvector) {
  for (int i=0;i<4;i++) fourvector[i] = m_fourvector[i];
}

BasicParticle BasicParticle::operator+(BasicParticle particle) {
  double resultant[4], fourvector2[4];

  particle.getFourVector(fourvector2);
  for (int i=0;i<4;i++) resultant[i] = m_fourvector[i] + fourvector2[i];
  return BasicParticle(resultant);
}

