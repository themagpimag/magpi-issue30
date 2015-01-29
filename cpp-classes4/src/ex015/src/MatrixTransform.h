#ifndef MATRIXTRANSFORM_H
#define MATRIXTRANSFORM_H

#include "IVectorTransform.h"

// A matrix transformation, inheriting from the
// IVectorTransform interface
class MatrixTransform: public IVectorTransform {
 public:
  MatrixTransform(double norm=1.0): // With default normalisation
    m_normalisation(norm){
    m_matrix[0][0] = 0.;
    m_matrix[1][0] = 1.;
    m_matrix[0][1] = -1.;
    m_matrix[1][1] = 0.;
  }
  virtual ~MatrixTransform(){};
  virtual TwoVector transform(const TwoVector &);
  virtual std::string str();

 private:
  double m_normalisation;
  double m_matrix[2][2];
};

#endif
