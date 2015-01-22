/* W. H. Bell
** A simple container.
*/

#ifndef BAG_H
#define BAG_H

class Bag {
public:
  /** Default constructor */
  Bag();

  /** Constructor with specified bag volume */
  Bag(double volume);

  /** A function to return the volume */
  double getVolume(void);

  /** A function to set the volume */
  void setVolume(double volume);

private:
  /** A data member to store the volume */
  double m_volume;
};

#endif
