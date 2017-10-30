#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  return true;
}

bool controller::operator ()() {
  return true;
}

