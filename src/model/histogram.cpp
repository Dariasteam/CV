#include "histogram.h"

histogram::histogram() :
  regular_r               (DEPTH),
  regular_g               (DEPTH),
  regular_b               (DEPTH),

  acumulated_r            (DEPTH),
  acumulated_g            (DEPTH),
  acumulated_b            (DEPTH),

  normalized_regular_r    (DEPTH),
  normalized_regular_g    (DEPTH),
  normalized_regular_b    (DEPTH),

  normalized_acumulated_r (DEPTH),
  normalized_acumulated_g (DEPTH),
  normalized_acumulated_b (DEPTH)
  {}

void histogram::generate_from_regular(unsigned size) {
  acumulated_r[0]            = regular_r[0];
  acumulated_g[0]            = regular_g[0];
  acumulated_b[0]            = regular_b[0];

  normalized_regular_r[0]    = double(regular_r[0]) / size;
  normalized_regular_g[0]    = double(regular_g[0]) / size;
  normalized_regular_b[0]    = double(regular_b[0]) / size;

  normalized_acumulated_r[0] = double(regular_r[0]) / size;
  normalized_acumulated_g[0] = double(regular_g[0]) / size;
  normalized_acumulated_b[0] = double(regular_b[0]) / size;

  for (unsigned i = 1; i < DEPTH; i++) {
    acumulated_r[i] = regular_r[i] + acumulated_r[i - 1];
    acumulated_g[i] = regular_g[i] + acumulated_g[i - 1];
    acumulated_b[i] = regular_b[i] + acumulated_b[i - 1];

    normalized_regular_r[i]    = double(regular_r[i])    / size;
    normalized_regular_g[i]    = double(regular_g[i])    / size;
    normalized_regular_b[i]    = double(regular_b[i])    / size;

    normalized_acumulated_r[i] = double(acumulated_r[i]) / size;
    normalized_acumulated_g[i] = double(acumulated_g[i]) / size;
    normalized_acumulated_b[i] = double(acumulated_b[i]) / size;
  }
}

void histogram::clear(std::vector<unsigned> &vec) {
  vec.clear();
  vec.resize(DEPTH);
}

void histogram::clear(std::vector<double> &vec) {
  vec.clear();
  vec.resize(DEPTH);
}

void histogram::clear() {  
  clear (regular_r);
  clear (regular_g);
  clear (regular_b);

  clear (acumulated_r);
  clear (acumulated_g);
  clear (acumulated_b);

  clear (normalized_regular_r);
  clear (normalized_regular_g);
  clear (normalized_regular_b);

  clear (normalized_acumulated_r);
  clear (normalized_acumulated_g);
  clear (normalized_acumulated_b);
}
