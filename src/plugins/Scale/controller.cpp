#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl),
  use_bilinear (false)
{
  connect(((menu*)mn),SIGNAL(updated_values(int,int)),this,SLOT(on_update_values(int,int)));
  connect(((menu*)mn)->get_check_bilinear(),SIGNAL(toggled(bool)),this,SLOT(on_update_bilinear(bool)));
}

void controller::on_update_values(int w, int h) {
  operator ()(w, h);
}

void controller::on_update_bilinear(bool b) {
  use_bilinear = b;
  operator ()(((menu*)view)->get_spin_width()->value(),
              ((menu*)view)->get_spin_height()->value());
}

bool controller::operator ()(double w, double h) {
  mdl->restore_backup();
  picture* original_img = mdl->get_image();
  picture* aux = original_img->make_copy();

  unsigned width = original_img->get_size().width();
  unsigned height = original_img->get_size().height();

  w /= 100;
  h /= 100;

  aux->resize(std::round(w * width), std::round(h * height));

  QImage* img = original_img->get_image();

  if (!use_bilinear) {
    aux->each_pixel_modificator_with_index([&](QColor color, unsigned i, unsigned j) -> QColor {
      return (img->pixelColor(std::round(double(i) / w),
                              std::round(double(j) / h)));
    });
  } else {
    aux->each_pixel_modificator_with_index([&](QColor color, unsigned i, unsigned j) -> QColor {
      std::vector<rgb_float_values> values;

      double m;

      double p = std::modf((double(i) / w), &m);
      double q = std::modf((double(j) / h), &m);

      i = std::floor(double(i) / w);
      j = std::floor(double(j) / h);

      for (int index_w = i; index_w <= i + 1; index_w++) {
        for (int index_h = j; index_h <= j + 1; index_h++) {
          QColor color = img->pixelColor(index_w, index_h);
          values.push_back({color.red(), color.green(), color.blue()});
        }
      }

      rgb_float_values A = values[1];
      rgb_float_values B = values[3];
      rgb_float_values C = values[0];
      rgb_float_values D = values[2];

      rgb_unsigned_values final;

      rgb_float_values Q;
      rgb_float_values R;

      Q.r = A.r + (B.r - A.r) * p;
      Q.g = A.g + (B.g - A.g) * p;
      Q.b = A.b + (B.b - A.b) * p;

      R.r = C.r + (D.r - C.r) * p;
      R.g = C.g + (D.g - C.g) * p;
      R.b = C.b + (D.b - C.b) * p;

      final.r = R.r + (Q.r - R.r) * q;
      final.g = R.g + (Q.g - R.g) * q;
      final.b = R.b + (Q.b - R.b) * q;

      return (QColor(final.r, final.g, final.b));
    });
  }

  original_img->restore_from(aux);
  emit update_inform();
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_image(image);
  return true;
}

