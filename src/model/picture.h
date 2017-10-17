#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <vector>
#include <functional>

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
  bool black_and_white;

  QImage* raw_image;
  QPixmap* pixmap;
  histogram histograms;
  unsigned average;           // media
  double mediana;             // esto en inglés
public:
  bool each_pixel_modificator (std::function<QColor (QColor)> lambda);
  bool each_pixel_iterator    (std::function<bool (QColor)> lambda);

  void generate_histograms ();
  void to_grayscale (const std::vector<double>&  transform);
  picture (QImage* image);
  inline QImage*  get_image  () { return raw_image; }
  inline QPixmap* get_pixmap () { return pixmap;    }  
  inline void update_pixmap () { pixmap->convertFromImage(*raw_image); }
  inline histogram get_histograms () { return histograms; }
  inline void set_black_and_white (bool b) { black_and_white = true; }
  inline bool get_black_and_white () { return black_and_white; }
};

#endif // IMAGE_H
