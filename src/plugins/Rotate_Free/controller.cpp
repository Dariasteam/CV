#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl),
  use_bilinear (true)
{
  connect(((menu*)mn)->get_slider_rotate(),SIGNAL(valueChanged(int)),this,SLOT(on_update_value(int)));
}

double controller::max_x(std::vector<std::pair<double, double> > &vec) {
  double max = -1;
  for (auto& pr : vec) {
    if (pr.first > max)
      max = pr.first;
  }
  return max;
}

double controller::max_y(std::vector<std::pair<double, double> > &vec) {
  double max = -1;
  for (auto& pr : vec) {
    if (pr.second > max)
      max = pr.second;
  }
  return max;
}

double controller::min_x(std::vector<std::pair<double, double> > &vec) {
  double min = 10000000;
  for (auto& pr : vec) {
    if (pr.first < min)
      min = pr.first;
  }
  return min;
}

double controller::min_y(std::vector<std::pair<double, double> > &vec) {
  double min = 10000000;
  for (auto& pr : vec) {
    if (pr.second < min)
      min = pr.second;
  }
  return min;
}

double controller::to_rad(double angle) {
  return angle * PI / 180;
}

std::pair<double, double> controller::direct_transformation(double x, double y, double ro) {
  double X = cos(ro) * x - sin(ro) * y;
  double Y = sin(ro) * x + cos(ro) * y;
  return {X, Y};
}

std::pair<double, double> controller::indirect_transformation(double X, double Y, double ro) {
  double x = cos(-ro) * X - sin(-ro) * Y;
  double y = sin(-ro) * X + cos(-ro) * Y;
  return {x, y};
}

void controller::on_update_value(int ro) {

  mdl->restore_backup();
  picture* original_img = mdl->get_image();
  picture* aux = original_img->make_copy();

  unsigned w = aux->get_size().width();
  unsigned h = aux->get_size().height();

  double rad_ro = to_rad(ro);

  // Encontrar las esquinas, transformación directa
  std::vector<std::pair<double, double>> corners;
  corners.push_back(direct_transformation(0, 0, rad_ro));
  corners.push_back(direct_transformation(0, h, rad_ro));
  corners.push_back(direct_transformation(w, h, rad_ro));
  corners.push_back(direct_transformation(w, 0, rad_ro));

  // Encontrar el paralelogramo
  unsigned new_w = std::round(fabs(max_x(corners) - min_x(corners)));
  unsigned new_h = std::round(fabs(max_y(corners) - min_y(corners)));

  aux->resize(new_w, new_h);
  QImage* img = original_img->get_image();

  std::pair<double, double> T = {min_x(corners), min_y(corners)};

  // Mapear la imagen, transformación indirecta

  unsigned origina_w = img->size().width();
  unsigned origina_h = img->size().height();

  aux->each_pixel_modificator_with_index([&](QColor color, unsigned i, unsigned j) -> QColor {
    std::pair<double, double> aux = indirect_transformation(T.first + double(i), T.second + double(j), rad_ro);
    if (aux.first < 0 || aux.second < 0 || aux.first > origina_w || aux.second > origina_h)
      return QColor(0, 0, 0);
    else
      return (img->pixelColor(std::round(aux.first), std::round(aux.second)));
  });


  original_img->restore_from(aux);

  emit update_inform();
}

bool controller::operator ()(double w, double h) {
  /*
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
  */
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_image(image);
  return true;
}

