#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>

class histogram {
private:
  std::vector <unsigned> regular;                // histograma
  std::vector <unsigned> acumulated;             // histograma acumulado
  std::vector <unsigned> normalized_regular;     // histograma normal normalizado
  std::vector <unsigned> normalized_acumulated;  // histograma acumulado normalizado
public:
  histogram();
};

#endif // HISTOGRAM_H
