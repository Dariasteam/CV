#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <vector>

#include "histogram.h"

/* Representa una imagen en memoria y la información
 * de su histograma.
 *
 * Contiene dos objetos para una misma imagen:
 *
 * QImage: clase optimizada para la manipulación a nivel de pixel
 * QPixmap: clase optimizada para la representación
 * */
class picture {
private:
  const std::vector<double> NTSC = { 0.299, 0.587, 0.114 };
  const std::vector<double> PAL  = { 0.222, 0.707, 0.071 };

  QImage* raw_image;
  QPixmap* pixmap;
  histogram* histograms;
  unsigned average;           // media
  double mediana;             // esto en inglés
public:    
  void to_grayscale (const std::vector<double>&  transform);
  picture (QImage* image);
  inline QImage*  get_image  () { return raw_image; }
  inline QPixmap* get_pixmap () { return pixmap;    }  
  inline void update_pixmap () { pixmap->convertFromImage(*raw_image); }
};

#endif // IMAGE_H
