#include "MatrixTransform.h"
#include <sstream>
#include <iomanip>

TwoVector MatrixTransform::transform(const TwoVector &twoVector){
  double x, y, new_x, new_y;
  x = twoVector.x();
  y = twoVector.y();
  new_x = m_normalisation * (x*m_matrix[0][0] + y*m_matrix[0][1]);
  new_y = m_normalisation * (x*m_matrix[1][0] + y*m_matrix[1][1]);
  return TwoVector(new_x,new_y);
}

std::string MatrixTransform::str(){
  std::stringstream ss;
  ss << std::setw(4) << m_normalisation << " x ";
  ss << "| " << std::setw(3) << m_matrix[0][0] << ", " << std::setw(3) << m_matrix[0][1] << " |" << std::endl;
  ss << "       | " << std::setw(3) << m_matrix[1][0] << ", " << std::setw(3) << m_matrix[1][1] << " |" << std::endl;
  return ss.str();
}
