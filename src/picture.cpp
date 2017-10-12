#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image)
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);   

  to_grayscale(PAL);
}

void picture::to_grayscale(const std::vector<double>& transform) {
  for (unsigned i = 0; i < raw_image->width(); i++) {
    for (unsigned j = 0; j < raw_image->height(); j++){

      QColor pixel = raw_image->pixelColor(i, j);

      unsigned gray = pixel.red()   * transform[0] +
                      pixel.green() * transform[1] +
                      pixel.blue()  * transform[2];

      raw_image->setPixelColor(i,j, QColor(gray, gray, gray));
    }
  }
  update_pixmap();
}

