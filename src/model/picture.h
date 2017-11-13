#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <vector>
#include <QSize>
#include <QColor>

#include <atomic>
#include <future>
#include <functional>
#include <math.h>

#include "histogram.h"
#include "../model/lut.h"

struct min_max_range {
            //   MIN      MAX
  std::pair <unsigned, unsigned> r;
  std::pair <unsigned, unsigned> g;
  std::pair <unsigned, unsigned> b;
};

struct rgb_float_values {
  double r;
  double g;
  double b;

  rgb_float_values operator *(const rgb_float_values& c) {
    return rgb_float_values {
      r * c.r,
      g * c.g,
      b * c.b,
    };
  }

  rgb_float_values operator /(const rgb_float_values& c) {
    return rgb_float_values {
      r / c.r,
      g / c.g,
      b / c.b,
    };
  }

  rgb_float_values operator -(const rgb_float_values& c) {
    return rgb_float_values {
      r - c.r,
      g - c.g,
      b - c.b,
    };
  }
};

struct rgb_unsigned_values {
  unsigned r;
  unsigned g;
  unsigned b;
};

struct picture_basic_info {
  rgb_float_values average;
  rgb_float_values deviation;
  rgb_float_values entropy;
  rgb_unsigned_values dynamic_range;
  min_max_range range;
};

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
  QString format;

  QImage* raw_image;
  QPixmap* pixmap;
  histogram histograms;
  picture_basic_info basic_info;
  unsigned sz;                    // area

  void generate_histograms    ();
  void generate_range         ();
  void generate_average       ();
  void generate_deviation     ();
  void generate_dynamic_range ();
  void generate_entropy       ();  
public:
  picture (QImage* image, QString f);
  picture (const picture& P);
  picture (const picture* P);

  virtual void subImage (const picture* pic);

  virtual picture* make_copy ();
  virtual void restore_from (const picture* pic);
  virtual void crop (picture* pic, QRect rect);

  QColor get_color (QPoint pos) { return raw_image->pixel(pos.x(), pos.y()); }
  void operator =(const picture& pic);

  virtual bool each_pixel_modificator (std::function<QColor (QColor)> lambda);
  virtual bool each_pixel_iterator    (std::function<bool (QColor)> lambda);
  virtual bool apply_lut              (const LUT* lut);

  void generate_basic_info();

  inline QImage*  get_image  () const { return raw_image; }
  inline QPixmap* get_pixmap () const { return pixmap;    }
  inline void update_pixmap () {
    generate_histograms();
    pixmap->convertFromImage(*raw_image);    
  }

  inline void set_pixmap (QPixmap* pix) { pixmap = pix; }

  inline QSize get_size () { return pixmap->size(); }
  inline unsigned get_sz () { return sz; }
  inline QString get_format () const { return format; }

  inline QImage* get_raw_image ()          const { return raw_image; }
  inline const histogram get_histograms () const { return histograms; }

  const picture_basic_info& get_basic_info () const { return basic_info; }

  inline void set_black_and_white (bool b)       { black_and_white = true; }
  inline bool is_black_and_white ()        const { return black_and_white; }
};

#endif // IMAGE_H
