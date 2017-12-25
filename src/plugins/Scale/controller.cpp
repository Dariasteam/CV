#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{
  connect(((menu*)mn),SIGNAL(updated_values(int,int)),this,SLOT(on_update_values(int,int)));
}

void controller::on_update_values(int w, int h) {
  operator ()(w, h);
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

  aux->each_pixel_modificator_with_index([&](QColor color, unsigned i, unsigned j) -> QColor {
    return (img->pixelColor(std::round(double(i) / w),
                            std::round(double(j) / h)));
  });

  original_img->restore_from(aux);
  emit update_inform();
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_image(image);
  return true;
}

