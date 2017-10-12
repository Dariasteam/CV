#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include <vector>
#include <QImage>

#define CHANEL_DEPTH 8
#define N_CHANELS 3

class histogram {
private:
  std::vector <unsigned> regular;                // histograma
  std::vector <unsigned> acumulated;             // histograma acumulado
  std::vector <unsigned> normalized_regular;     // histograma normal normalizado
  std::vector <unsigned> normalized_acumulated;  // histograma acumulado normalizado
public:
  histogram(QImage* img);
};

#endif // HISTOGRAM_H
