#include "histogram.h"

histogram::histogram() :
  regular               (DEPTH),
  acumulated            (DEPTH),
  normalized_regular    (DEPTH),
  normalized_acumulated (DEPTH)
  {}

void histogram::generate_from_regular() {
  acumulated[0]            = regular[0];
  normalized_regular[0]    = float(regular[0]) / float(DEPTH);
  normalized_acumulated[0] = float(regular[0]) / float(DEPTH);

  for (unsigned i = 1; i < DEPTH; i++) {
    acumulated[i] = regular[i] + acumulated[i - 1];
    normalized_regular[i]    = float(regular[i])    / DEPTH;
    normalized_acumulated[i] = float(acumulated[i]) / DEPTH;
  }


}
