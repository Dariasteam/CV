#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

#include <iostream>

bool controller::operator () (picture* image, canvas_image_label* canvas) {

  ((PluginModelCanvas*)mdl)->set_image(image);
  ((PluginModelCanvas*)mdl)->create_selectable_pixmap(*image->get_pixmap());  
  operator ()();

  emit set_canvas_image_label((QLabel*)((PluginModelCanvas*)mdl)->get_label());
}

bool controller::operator ()() {  
  emit update_inform();
  return true;
}
