/* W. H. Bell
** A simple representation of a particle.
*/

#ifndef BASIC_PARTICLE_H
#define BASIC_PARTICLE_H

class BasicParticle {
public:
  /** The default constructor */
  BasicParticle(void);

  /** Construct a particle from a fourvector. */
  BasicParticle(double *fourvector);

  /** Set the four vector for this particle */
  void assignFourVector(double *);

  /** Get the four vector for this particle */
  void getFourVector(double *);

  /** Get the transverse momentum */
  double getPt(void);

  /** Get the mass */
  double getMass(void);

  /** Addition operator */
  BasicParticle operator+(BasicParticle);

protected:
  /** A function to calculate the transverse momentum */
  void calculatePt();

  /** A function to calculate the mass */
  void calculateMass();

  /** A data member to store the fourvector */
  double m_fourvector[4];

  /** A data member to store the transverse momentum */
  double m_pt;

  /** A data member to store the mass */
  double m_mass;
};

#endif
