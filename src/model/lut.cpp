#include "lut.h"

LUT::LUT() :
  r(DEPTH),
  g(DEPTH),
  b(DEPTH)
{}

#include <future>
#include <functional>

void LUT::each_value_modificator(unsigned from ,unsigned to ,
                                 std::function<double (double)> lambda,
                                 std::vector<double>& vec) {
  if (from > DEPTH)
    from = 0;
  if (to > DEPTH)
    to = DEPTH;

  unsigned to_quad = to / 6;


  std::function<void(unsigned, unsigned)> func = [&](unsigned min,
                                                     unsigned max) {
    for (unsigned i = min; i < max; i++) {
      double value = lambda(i);
      if (value > 255)
        vec[i] = 255;
      else if (value < 0)
        vec[i] = 0;
      else
        vec[i] = value;
    }
  };

  std::future<void> f1 = std::async(func, 0, to_quad);
  std::future<void> f2 = std::async(func, to_quad    , to_quad * 2);
  std::future<void> f3 = std::async(func, to_quad * 2, to_quad * 3);
  std::future<void> f4 = std::async(func, to_quad * 3, to_quad * 4);
  std::future<void> f5 = std::async(func, to_quad * 4, to_quad * 5);
  std::future<void> f6 = std::async(func, to_quad * 5, to_quad * 6);

  f1.get();
  f2.get();
  f3.get();
  f4.get();
  f5.get();
  f6.get();
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

