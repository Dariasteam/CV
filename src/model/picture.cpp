#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image),
  black_and_white (false)
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);     

  generate_histograms();
}

picture::picture(const picture& P) :
  raw_image (new QImage(*P.get_image())),
  pixmap (new QPixmap (*P.get_pixmap())),
  black_and_white (P.is_black_and_white()),
  histograms (P.get_histograms())
{}

picture::picture(const picture* P) :
  raw_image (new QImage(*P->get_image())),
  pixmap (new QPixmap (*P->get_pixmap())),
  black_and_white (P->is_black_and_white()),
  histograms (P->get_histograms())
{}

void picture::generate_histograms() {
  histograms.clear();
  each_pixel_iterator([&](QColor pixel) -> bool{
    histograms.regular_r[pixel.red()  ]+= 1;
    histograms.regular_g[pixel.green()]+= 1;
    histograms.regular_b[pixel.blue() ]+= 1;    
  });  
  histograms.generate_from_regular();
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
