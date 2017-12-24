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

picture::picture(const picture& P) : QObject(nullptr) {
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

bool picture::each_pixel_modificator(std::function<QColor (QColor)> lambda) {
  unsigned number = N_THREADS;

  std::atomic<bool> image_in_use (false);
  unsigned aux_width  = raw_image->width() / number;
  unsigned height = raw_image->height();

  std::vector<std::future<void>> promises (number + 1);

  auto async_function = [&](unsigned min_w, unsigned max_w) {
    for (unsigned i = min_w; i < max_w; i++) {
      for (unsigned j = 0; j < height; j++) {
        QColor input_color = raw_image->pixelColor(i, j);
        QColor output_color = lambda (input_color);
        while (image_in_use.load()) {}
        image_in_use.store(true);
        raw_image->setPixelColor(i, j, output_color);
        image_in_use.store(false);
      }      
    }        
  };  

  for (unsigned i = 0; i < number; i++) {
    promises[i] =  std::async(async_function,
                              aux_width * i,
                              aux_width * (i + 1));
  }

  promises[number] =  std::async(async_function,
                                 aux_width * number,
                                 raw_image->width());

  emit update_progress(7);
  for (auto& promise : promises) {
    promise.get();
    emit update_progress(7);
  }

  generate_basic_info();
  update_pixmap();
}



bool picture::each_pixel_modificator_with_index(std::function<QColor (QColor, unsigned, unsigned)> lambda) {
  unsigned number = N_THREADS;

  std::atomic<bool> image_in_use (false);
  unsigned aux_width  = raw_image->width() / number;
  unsigned height = raw_image->height();

  std::vector<std::future<void>> promises (number + 1);

  auto async_function = [&](unsigned min_w, unsigned max_w) {
    for (unsigned i = min_w; i < max_w; i++) {
      for (unsigned j = 0; j < height; j++) {
        QColor input_color = raw_image->pixelColor(i, j);
        QColor output_color = lambda (input_color, i, j);
        while (image_in_use.load()) {}
        image_in_use.store(true);
        raw_image->setPixelColor(i, j, output_color);
        image_in_use.store(false);
      }
    }
  };

  for (unsigned i = 0; i < number; i++) {
    promises[i] =  std::async(async_function,
                              aux_width * i,
                              aux_width * (i + 1));
  }

  promises[number] =  std::async(async_function,
                                 aux_width * number,
                                 raw_image->width());

  emit update_progress(7);
  for (auto& promise : promises) {
    promise.get();
    emit update_progress(7);
  }

  generate_histograms();
  generate_basic_info();
  update_pixmap();
}




bool picture::each_pixel_iterator(std::function<bool (QColor)> lambda) {    
  for (unsigned i = 0; i < raw_image->width(); i++) {
    for (unsigned j = 0; j < raw_image->height(); j++) {      
      lambda (raw_image->pixelColor(i, j));
    }
  }
}

bool picture::apply_lut(const LUT* lut) {
  each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned r = std::round (lut->r [pixel.red()  ]);
    unsigned g = std::round (lut->g [pixel.green()]);
    unsigned b = std::round (lut->b [pixel.blue() ]);
    return QColor(r, g, b);
  });
}

bool picture::apply_filter(const filter* flitr) {  
  QImage* aux_img = new QImage(*raw_image);

  unsigned number = N_THREADS;

  unsigned filter_size = flitr->get_size();
  unsigned offset = filter_size / 3;

  std::atomic<bool> image_in_use (false);
  unsigned aux_width  = raw_image->width() / number;
  unsigned height = raw_image->height();

  std::vector<std::future<void>> promises (number);

  auto async_function = [&](unsigned min_w, unsigned max_w) {
    for (unsigned i = min_w; i < max_w; i++) {
      for (unsigned j = offset; j < height - offset; j++) {
        while (image_in_use.load()) {}
        image_in_use.store(true);

        // Obtener la región de vecindad        

        rgb_float_values acumulator;

        for (unsigned k = 0; k < filter_size; k++) {
          for (unsigned h = 0; h < filter_size; h++) {
            QColor color = raw_image->pixelColor(i + k - offset, j + h - offset);
            int element = flitr->get_element(k,h);
            acumulator.r += element * color.red();
            acumulator.g += element * color.green();
            acumulator.b += element * color.blue();
          }
        }                

        unsigned double_f_size = filter_size * filter_size;

        acumulator.r = acumulator.r / double_f_size;
        acumulator.g = acumulator.g / double_f_size;
        acumulator.b = acumulator.b / double_f_size;

        aux_img->setPixelColor(i,j,QColor(acumulator.r,
                                          acumulator.g,
                                          acumulator.b));

        acumulator = {0, 0, 0};
        image_in_use.store(false);
      }
    }
  };

  promises[0] = std::async(async_function, offset, aux_width);

  for (unsigned i = 1; i < number - 1; i++)
    promises[i] =  std::async(async_function, aux_width * i, aux_width * (i + 1));

  promises[number - 1] =  std::async(async_function,
                                     aux_width * (number - 1),
                                     raw_image->width() - offset);

  emit update_progress(7);
  for (auto& promise : promises) {
    promise.get();
    emit update_progress(7);
  }

  QImage*  old_img = raw_image;
  QPixmap* old_pix = pixmap;

  raw_image = aux_img;
  pixmap = new QPixmap();
  pixmap->fromImage(*aux_img);

  delete old_img;
  delete old_pix;

  generate_histograms();
  generate_basic_info();
  update_pixmap();
}

void picture::subImage(const picture *pic) {
  for (unsigned i = 0; i < get_size().width(); i++) {
    for (unsigned j = 0; j < get_size().height(); j++) {
      QColor a_color = get_raw_image()->pixel(i, j);
      QColor b_color = pic->get_raw_image()->pixel(i, j);
      QColor final_color;

      final_color.setRed  ( abs(a_color.red()   - b_color.red()));
      final_color.setGreen( abs(a_color.green() - b_color.green()));
      final_color.setBlue ( abs(a_color.blue()  - b_color.blue()));

      get_raw_image()->setPixelColor(i, j, final_color);
    }
  }
  generate_histograms();
  generate_basic_info();
  update_pixmap();
}

void picture::operator = (const picture& pic) {
  pixmap = pic.get_pixmap();
  raw_image = pic.get_raw_image();
  black_and_white = pic.is_black_and_white();
  histograms = pic.get_histograms();
}
