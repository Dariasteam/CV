#include "lut.h"

LUT::LUT() :
  r(DEPTH),
  g(DEPTH),
  b(DEPTH)
{}

void LUT::each_value_modificator(std::function<double (double)> lambda,
                                 std::vector<double>& vec) {
  for (unsigned i = 0; i < DEPTH; i++) {
    double value = lambda(i);
    if (value > 255)
      vec[i] = 255;
    else if (value < 0)
      vec[i] = 0;
    else
      vec[i] = value;
  }
}

void LUT::each_value_modificator_r(std::function<double (double)> lambda) {
 each_value_modificator(lambda, r);
}

void LUT::each_value_modificator_g(std::function<double (double)> lambda) {
 each_value_modificator(lambda, g);
}

void LUT::each_value_modificator_b(std::function<double (double)> lambda) {
 each_value_modificator(lambda, b);
}

