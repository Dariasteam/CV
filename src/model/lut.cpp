#include "lut.h"

LUT::LUT() :
  r(DEPTH),
  g(DEPTH),
  b(DEPTH)
{}

void LUT::each_value_modificator(unsigned from ,unsigned to ,
                                 std::function<double (double)> lambda,
                                 std::vector<double>& vec) {
  if (from > DEPTH - 1)
    from = 0;
  if (to > DEPTH - 1)
    to = DEPTH;

  std::function<void(unsigned, unsigned)> func = [&](unsigned min,
                                                     unsigned max) {
    for (unsigned i = min; i < max; i++) {
      double value = lambda(i);
      if (value > DEPTH - 1)
        vec[i] = DEPTH - 1;
      else if (value < 0)
        vec[i] = 0;
      else
        vec[i] = value;
    }
  };

  unsigned n_segments = (N_THREADS);

  std::vector<std::future<void>> promises (n_segments + 1);
  unsigned segment = (to - from) / n_segments;

  for (unsigned i = 0; i < n_segments; i++)
    promises[i] = std::async(func, from + (segment * i), from + (segment * (i + 1)));      

  promises[n_segments] = std::async(func, from + (segment * (n_segments - 1)), to);

  for (auto& promise : promises)
    promise.get();
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

