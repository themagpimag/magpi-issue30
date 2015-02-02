#include "TwoVector.h"
#include "MatrixTransform.h"
#include <iostream>
#include <cmath>

// A program to demonstrate how to use an interface class
int main() {
  TwoVector vec1(3.,4.);  // A 2d vector (x=3, y=4)
  IVectorTransform *t = new MatrixTransform(1); // Create a new transform on the heap
  TwoVector vec2 = t->transform(vec1);  // Transform the vector, to produce a new vector
  std::cout << t->str() << std::endl;  // Print the string form of the transform
  std::cout << "vec1=" << vec1 << ", vec2=" << vec2 << std::endl;  // Print the vectors
  delete t; // Delete the matrix transform pointer
  return 0;
}
