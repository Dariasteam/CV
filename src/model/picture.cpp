#include "picture.h"

picture::picture(QImage* image, QString f) :
  raw_image (image),
  black_and_white (false),
  sz (image->width() * image->height()),
  format (f)
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);     

  generate_histograms();
  generate_basic_info();
}

picture::picture(const picture& P) {
  QImage*  aux_1 = raw_image;
  QPixmap* aux_2 = pixmap;

  raw_image = new QImage  (*P.get_image());
  pixmap =    new QPixmap (*P.get_pixmap());

  //delete aux_1;
  //delete aux_2;

  black_and_white  = P.is_black_and_white();
  histograms = P.get_histograms();
  basic_info = P.get_basic_info();
}

picture::picture(const picture* P) {
  QImage*  aux_1 = raw_image;
  QPixmap* aux_2 = pixmap;

  raw_image = new QImage(*P->get_image());
  pixmap = new QPixmap (*P->get_pixmap());

  //delete aux_1;
  //delete aux_2;

  black_and_white  = P->is_black_and_white();
  histograms = P->get_histograms();
  basic_info = P->get_basic_info();
}

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

#include <iostream>

void picture::restore_from(const picture *pic) {
  QImage*  aux_1 = raw_image;
  QPixmap* aux_2 = pixmap;

  raw_image = new QImage(*pic->get_raw_image());
  pixmap = new QPixmap (QPixmap::fromImage(*raw_image));

  //delete aux_1;
  //delete aux_2;

  black_and_white = pic->is_black_and_white();
  histograms = pic->get_histograms();
  basic_info = pic->get_basic_info();
}

void picture::crop (picture* pic, QRect rect) {
  QImage*  aux_1 = raw_image;
  QPixmap* aux_2 = pixmap;

  raw_image = new QImage(raw_image->copy(rect));
  pixmap = new QPixmap (pixmap->fromImage(*raw_image));

  //delete aux_1;
  //delete aux_2;

  black_and_white = pic->is_black_and_white();
  generate_histograms();
  generate_basic_info();
}

#include <atomic>
#include <future>

bool picture::each_pixel_modificator(std::function<QColor (QColor)> lambda) {

  std::atomic<bool> image_in_use (false);
  unsigned aux_width = raw_image->width() / 3;
  unsigned aux_height = raw_image->height() / 3;

  auto async_function = [&](unsigned min_w, unsigned min_h,
                            unsigned max_w, unsigned max_h) {
    for (unsigned i = min_w; i < max_w; i++) {
      for (unsigned j = min_h; j < max_h; j++){
        QColor input_color = raw_image->pixelColor(i, j);
        QColor output_color = lambda (input_color);
        while (image_in_use.load()) {}
        image_in_use.store(true);
        raw_image->setPixelColor(i, j, output_color);
        image_in_use.store(false);
      }
    }
  };

  std::future<void> p1 = std::async(async_function, 0, 0, aux_width, aux_height);
  std::future<void> p2 = std::async(async_function, aux_width, 0, aux_width * 2, aux_height);
  std::future<void> p3 = std::async(async_function, aux_width * 2, 0, aux_width * 3, aux_height);

  std::future<void> p4 = std::async(async_function, 0, aux_height, aux_width, aux_height * 2);
  std::future<void> p5 = std::async(async_function, aux_width, aux_height, aux_width * 2, aux_height * 2);
  std::future<void> p6 = std::async(async_function, aux_width * 2, aux_height, aux_width * 3, aux_height * 2);

  std::future<void> p7 = std::async(async_function, 0, aux_height * 2, aux_width, aux_height * 3);
  std::future<void> p8 = std::async(async_function, aux_width, aux_height * 2, aux_width * 2, aux_height * 3);
  std::future<void> p9 = std::async(async_function, aux_width * 2, aux_height * 2, aux_width * 3, aux_height * 3);


  p1.get();
  p2.get();
  p3.get();
  p4.get();
  p5.get();
  p6.get();
  p7.get();
  p8.get();
  p9.get();
/*
  std::future<void> p = std::async(async_function, 0, 0, aux_width * 2, aux_height *2 );
  p.get();
  */

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

bool picture::apply_lut(const LUT *lut) {

}


void picture::operator = (const picture& pic) {
  pixmap = pic.get_pixmap();
  raw_image = pic.get_raw_image();
  black_and_white = pic.is_black_and_white();
  histograms = pic.get_histograms();
}
