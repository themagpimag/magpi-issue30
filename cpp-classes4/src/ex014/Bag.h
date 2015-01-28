/* W. H. Bell
** A simple container.
*/

#ifndef BAG_H
#define BAG_H

class Bag {
public:
  Bag(double volume=0): 
  m_volume(volume) {
  }

  double volume(void){
    return m_volume;
  }

  void setVolume(double volume){
    m_volume = volume;
  }

private:
  double m_volume; // A data member to store the volume
};

#endif
