#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image)
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);   

  //to_grayscale(PAL);

  generate_histograms();

  std::function<QColor (QColor as)> {

  };
}

void picture::generate_histograms() {
  each_pixel_iterator([&](QColor pixel) -> bool{
    histograms.regular_r[pixel.red()  ]+= 1;
    histograms.regular_g[pixel.green()]+= 1;
    histograms.regular_b[pixel.blue() ]+= 1;
  });
  histograms.generate_from_regular();
}

void picture::to_grayscale(const std::vector<double>& transform) {
  each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = pixel.red()   * transform[0] +
                    pixel.green() * transform[1] +
                    pixel.blue()  * transform[2];

    return QColor(gray, gray, gray);
  });
}

bool picture::each_pixel_modificator(std::function<QColor (QColor)> lambda) {
  for (unsigned i = 0; i < raw_image->width(); i++) {
    for (unsigned j = 0; j < raw_image->height(); j++){
      raw_image->setPixelColor(i, j, lambda (raw_image->pixelColor(i, j)));
    }
  }
  update_pixmap();
}

bool picture::each_pixel_iterator(std::function<bool (QColor)> lambda) {
  for (unsigned i = 0; i < raw_image->width(); i++) {
    for (unsigned j = 0; j < raw_image->height(); j++){
      lambda (raw_image->pixelColor(i, j));
    }
  }
}
