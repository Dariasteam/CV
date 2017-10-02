#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>
#include <vector>


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
  QImage* raw_image;
  QPixmap* pixmap;  
public:  
  picture (QImage* image);
  inline QImage*  get_image  () { return raw_image; }
  inline QPixmap* get_pixmap () { return pixmap;    }
};

#endif // IMAGE_H
