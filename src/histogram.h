#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <QImage>

#define DEPTH 255

struct histogram {
  std::vector <unsigned> regular;                // histograma
  std::vector <unsigned> acumulated;             // histograma acumulado
  std::vector <unsigned> normalized_regular;     // histograma normal normalizado
  std::vector <unsigned> normalized_acumulated;  // histograma acumulado normalizado

  histogram();

  void generate_from_regular ();
};

#endif // HISTOGRAM_H
