#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {

  mdl->set_image(image);

  picture* aux = image->make_copy();

  unsigned width  = image->get_image()->size().width();
  unsigned height = image->get_image()->size().height();
  QImage* img = image->get_image();

  aux->each_pixel_modificator_with_index([&](QColor color, unsigned i, unsigned j) -> QColor {
    return (img->pixelColor(width - i, height - j));
  });

  image->restore_from(aux);

  emit update_inform();

  return true;
}

