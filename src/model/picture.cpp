#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image),
  black_and_white (false)
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);   

  //to_grayscale(PAL);

  generate_histograms();

  std::function<QColor (QColor as)> {

  };
}

picture::picture(const picture& P) :
  raw_image (new QImage(*P.get_image())),
  pixmap (new QPixmap (*P.get_pixmap())),
  black_and_white (P.get_black_and_white()),
  histograms (P.get_histograms())
{}

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
  set_black_and_white(true);
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
