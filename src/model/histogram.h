#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <QImage>

#define DEPTH 255

struct histogram {
  std::vector <unsigned> regular_r;                // histograma
  std::vector <unsigned> regular_g;                // histograma
  std::vector <unsigned> regular_b;                // histograma

  std::vector <unsigned> acumulated_r;             // histograma acumulado
  std::vector <unsigned> acumulated_g;             // histograma acumulado
  std::vector <unsigned> acumulated_b;             // histograma acumulado

  std::vector <unsigned> normalized_regular_r;     // histograma normal normalizado
  std::vector <unsigned> normalized_regular_g;     // histograma normal normalizado
  std::vector <unsigned> normalized_regular_b;     // histograma normal normalizado

  std::vector <unsigned> normalized_acumulated_r;  // histograma acumulado normalizado
  std::vector <unsigned> normalized_acumulated_g;  // histograma acumulado normalizado
  std::vector <unsigned> normalized_acumulated_b;  // histograma acumulado normalizado

  histogram();

  void generate_from_regular ();
  void clear ();
};

#endif // HISTOGRAM_H

