#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image),
  black_and_white (false),
  sz (image->width() * image->height())
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);     

  generate_histograms();
  generate_range();
  generate_average();
  generate_deviation();


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

void picture::generate_range() {
  range = {{0, 0}, {0, 0}, {0, 0}};
  // RED
  for (unsigned i = 0; i < DEPTH; i++)
    if (histograms.regular_r[i] > 0) { range.r.first = i; break; }
  for (int i = DEPTH - 1; i >= 0; i--)
    if (histograms.regular_r[i] > 0) { range.r.second = i; break; }

  // GREEN
  for (unsigned i = 0; i < DEPTH; i++)
    if (histograms.regular_g[i] > 0) { range.g.first = i; break; }
  for (int i = DEPTH - 1; i >= 0; i--)
    if (histograms.regular_g[i] > 0) { range.g.second = i; break; }

  // BLUE
  for (unsigned i = 0; i < DEPTH; i++)
    if (histograms.regular_b[i] > 0) { range.b.first = i; break; }
  for (int i = DEPTH - 1; i >= 0; i--)
    if (histograms.regular_b[i] > 0) { range.b.second = i; break; }
}

#include <iostream>

void picture::generate_average() {
  average  ={0, 0, 0};
  for (unsigned i = range.r.first; i <= range.r.second; i++)
    average.r += histograms.regular_r[i] * i;
  for (unsigned i = range.g.first; i <= range.g.second; i++)
    average.g += histograms.regular_g[i] * i;
  for (unsigned i = range.b.first; i <= range.b.second; i++)
    average.b += histograms.regular_b[i] * i;

  average.r /= sz;
  average.g /= sz;
  average.b /= sz;
}

void picture::generate_deviation() {
  deviation = {0 ,0, 0};
  for (unsigned i = range.r.first; i <= range.r.second; i++)
    deviation.r += (histograms.regular_r[i] * pow(i - average.r, 2));
  for (unsigned i = range.g.first; i <= range.g.second; i++)
    deviation.g += (histograms.regular_g[i] * pow(i - average.g, 2));
  for (unsigned i = range.b.first; i <= range.b.second; i++)
    deviation.b += (histograms.regular_b[i] * pow(i - average.b, 2));

  deviation.r = sqrt(deviation.r / sz);
  deviation.g = sqrt(deviation.g / sz);
  deviation.b = sqrt(deviation.b / sz);
}

picture* picture::make_copy() {
  return new picture (this);
}

void picture::restore_from(picture *pic) {
  (*pixmap)    = (*pic->get_pixmap());
  (*raw_image) = (*pic->get_raw_image());
  black_and_white = pic->is_black_and_white();
  histograms = pic->get_histograms();
}

bool picture::each_pixel_modificator(std::function<QColor (QColor)> lambda) {
  for (unsigned i = 0; i < raw_image->width(); i++) {
    for (unsigned j = 0; j < raw_image->height(); j++){
      raw_image->setPixelColor(i, j, lambda (raw_image->pixelColor(i, j)));
    }
  }
  generate_histograms();
  generate_range();
  update_pixmap();
}

bool picture::each_pixel_iterator(std::function<bool (QColor)> lambda) {
  for (unsigned i = 0; i < raw_image->width(); i++) {
    for (unsigned j = 0; j < raw_image->height(); j++){
      lambda (raw_image->pixelColor(i, j));
    }
  }
}

void picture::operator = (const picture& pic) {
  pixmap = pic.get_pixmap();
  raw_image = pic.get_raw_image();
  black_and_white = pic.is_black_and_white();
  histograms = pic.get_histograms();
}
