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

void histogram::generate_from_regular() {
  acumulated_r[0]            = regular_r[0];
  acumulated_g[0]            = regular_g[0];
  acumulated_b[0]            = regular_b[0];

  normalized_regular_r[0]    = float(regular_r[0]) / float(DEPTH);
  normalized_regular_g[0]    = float(regular_g[0]) / float(DEPTH);
  normalized_regular_b[0]    = float(regular_b[0]) / float(DEPTH);

  normalized_acumulated_r[0] = float(regular_r[0]) / float(DEPTH);
  normalized_acumulated_g[0] = float(regular_g[0]) / float(DEPTH);
  normalized_acumulated_b[0] = float(regular_b[0]) / float(DEPTH);

  for (unsigned i = 1; i < DEPTH; i++) {
    acumulated_r[i] = regular_r[i] + acumulated_r[i - 1];
    acumulated_g[i] = regular_g[i] + acumulated_g[i - 1];
    acumulated_b[i] = regular_b[i] + acumulated_b[i - 1];

    normalized_regular_r[i]    = float(regular_r[i])    / DEPTH;
    normalized_regular_g[i]    = float(regular_g[i])    / DEPTH;
    normalized_regular_b[i]    = float(regular_b[i])    / DEPTH;

    normalized_acumulated_r[i] = float(acumulated_r[i]) / DEPTH;
    normalized_acumulated_g[i] = float(acumulated_g[i]) / DEPTH;
    normalized_acumulated_b[i] = float(acumulated_b[i]) / DEPTH;
  }
}
