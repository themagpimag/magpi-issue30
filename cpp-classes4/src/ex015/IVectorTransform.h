#ifndef IVECTORTRANSFORM_H
#define IVECTORTRANSFORM_H

#include "TwoVector.h"
#include <string>

// A transform interface: a purely abstract base class.
class IVectorTransform {
 public:
  virtual ~IVectorTransform(){};
  virtual TwoVector transform(const TwoVector &) = 0; // Not implemented
  virtual std::string str() = 0; // Not implemented
};

#endif
