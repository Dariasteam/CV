#include "lut.h"

LUT::LUT() :
  r(DEPTH),
  g(DEPTH),
  b(DEPTH)
{}

void LUT::each_value_modificator(unsigned from ,unsigned to ,
                                 std::function<double (double)> lambda,
                                 std::vector<double>& vec) {
  if (from > DEPTH)
    from = 0;
  if (to > DEPTH)
    to = DEPTH;


  for (unsigned i = from; i < to; i++) {
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
 each_value_modificator(0, DEPTH, lambda, r);
}

void LUT::each_value_modificator_g(std::function<double (double)> lambda) {
 each_value_modificator(0, DEPTH, lambda, g);
}

void LUT::each_value_modificator_b(std::function<double (double)> lambda) {
 each_value_modificator(0, DEPTH, lambda, b);
}

void LUT::each_modificator_from_to(unsigned from, unsigned to,
                                   std::function<double (double)> lambda) {
  each_value_modificator(from, to, lambda, r);
  each_value_modificator(from, to, lambda, g);
  each_value_modificator(from, to, lambda, b);
}

