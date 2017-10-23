#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image),
  black_and_white (false),
  sz (image->width() * image->height())
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);     

  generate_histograms();
  generate_basic_info();
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
  histograms.generate_from_regular(sz);
}

void picture::generate_range() {
  basic_info.range = {{0, 0}, {0, 0}, {0, 0}};
  // RED
  for (unsigned i = 0; i < DEPTH; i++)
    if (histograms.regular_r[i] > 0) { basic_info.range.r.first = i; break; }
  for (int i = DEPTH - 1; i >= 0; i--)
    if (histograms.regular_r[i] > 0) { basic_info.range.r.second = i; break; }

  // GREEN
  for (unsigned i = 0; i < DEPTH; i++)
    if (histograms.regular_g[i] > 0) { basic_info.range.g.first = i; break; }
  for (int i = DEPTH - 1; i >= 0; i--)
    if (histograms.regular_g[i] > 0) { basic_info.range.g.second = i; break; }

  // BLUE
  for (unsigned i = 0; i < DEPTH; i++)
    if (histograms.regular_b[i] > 0) { basic_info.range.b.first = i; break; }
  for (int i = DEPTH - 1; i >= 0; i--)
    if (histograms.regular_b[i] > 0) { basic_info.range.b.second = i; break; }
}

void picture::generate_basic_info() {
  generate_range();
  generate_average();
  generate_deviation();
  generate_dynamic_range();
  generate_entropy();
}

void picture::generate_average() {
  basic_info.average  ={0, 0, 0};
  for (unsigned i = basic_info.range.r.first; i <= basic_info.range.r.second; i++)
    basic_info.average.r += histograms.regular_r[i] * i;
  for (unsigned i = basic_info.range.g.first; i <= basic_info.range.g.second; i++)
    basic_info.average.g += histograms.regular_g[i] * i;
  for (unsigned i = basic_info.range.b.first; i <= basic_info.range.b.second; i++)
    basic_info.average.b += histograms.regular_b[i] * i;

  basic_info.average.r /= sz;
  basic_info.average.g /= sz;
  basic_info.average.b /= sz;
}

void picture::generate_deviation() {
  basic_info.deviation = {0 ,0, 0};
  for (unsigned i = basic_info.range.r.first; i <= basic_info.range.r.second; i++)
    basic_info.deviation.r += (histograms.regular_r[i] * pow(i - basic_info.average.r, 2));
  for (unsigned i = basic_info.range.g.first; i <= basic_info.range.g.second; i++)
    basic_info.deviation.g += (histograms.regular_g[i] * pow(i - basic_info.average.g, 2));
  for (unsigned i = basic_info.range.b.first; i <= basic_info.range.b.second; i++)
    basic_info.deviation.b += (histograms.regular_b[i] * pow(i - basic_info.average.b, 2));

  basic_info.deviation.r = sqrt(basic_info.deviation.r / sz);
  basic_info.deviation.g = sqrt(basic_info.deviation.g / sz);
  basic_info.deviation.b = sqrt(basic_info.deviation.b / sz);
}

void picture::generate_dynamic_range() {
  basic_info.dynamic_range = {0, 0, 0};
  for (unsigned i = basic_info.range.r.first; i <= basic_info.range.r.second; i++)
    if (histograms.regular_r[i] > 0) { basic_info.dynamic_range.r++; }
  for (unsigned i = basic_info.range.g.first; i <= basic_info.range.g.second; i++)
    if (histograms.regular_g[i] > 0) { basic_info.dynamic_range.g++; }
  for (unsigned i = basic_info.range.b.first; i <= basic_info.range.b.second; i++)
    if (histograms.regular_b[i] > 0) { basic_info.dynamic_range.b++; }
}

void picture::generate_entropy() {
  basic_info.entropy = {0, 0, 0};
  for (unsigned i = basic_info.range.r.first; i <= basic_info.range.r.second; i++) {
    double value = histograms.normalized_regular_r[i];
    if (value > 0) { basic_info.entropy.r += (value * log2 (value)); }
  }
  for (unsigned i = basic_info.range.g.first; i <= basic_info.range.g.second; i++) {
    double value = histograms.normalized_regular_g[i];
    if (value > 0) { basic_info.entropy.g += (value * log2 (value)); }
  }
  for (unsigned i = basic_info.range.b.first; i <= basic_info.range.g.second; i++) {
    double value = histograms.normalized_regular_b[i];
    if (value > 0) { basic_info.entropy.b += (value * log2 (value)); }
  }

  basic_info.entropy.r = -basic_info.entropy.r;
  basic_info.entropy.g = -basic_info.entropy.g;
  basic_info.entropy.b = -basic_info.entropy.b;
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
  generate_basic_info();
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
