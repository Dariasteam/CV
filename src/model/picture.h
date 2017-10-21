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
class picture : public QObject {
private:  
  bool black_and_white;

  QImage* raw_image;
  QPixmap* pixmap;
  histogram histograms;
  unsigned average;           // media
  double mediana;             // esto en inglés

public:
  picture (QImage* image);
  picture (const picture& P);
  picture (const picture* P);

  virtual picture* make_copy ();
  virtual void copy_from (picture* pic);

  void operator =(const picture& pic);

  virtual bool each_pixel_modificator (std::function<QColor (QColor)> lambda);
  virtual bool each_pixel_iterator    (std::function<bool (QColor)> lambda);

  void generate_histograms ();  

  inline QImage*  get_image  () const { return raw_image; }
  inline QPixmap* get_pixmap () const { return pixmap;    }
  inline void update_pixmap () {
    generate_histograms();
    pixmap->convertFromImage(*raw_image);    
  }

  inline QImage* get_raw_image () const { return raw_image; }

  inline histogram get_histograms () const { return histograms; }
  inline void set_black_and_white (bool b) { black_and_white = true; }
  inline bool is_black_and_white () const { return black_and_white; }
};

#endif // IMAGE_H
