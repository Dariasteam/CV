#include "lut.h"

LUT::LUT() :
  r(DEPTH),
  g(DEPTH),
  b(DEPTH)
{}

void LUT::each_value_modificator(std::function<double (double)> lambda,
                                 std::vector<double>& vec) {
  for (unsigned i = 0; i < DEPTH; i++)
    vec[i] = lambda(i);
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

