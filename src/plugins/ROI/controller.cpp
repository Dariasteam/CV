#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, canvas_image_label* canvas) {

  ((PluginModelCanvas*)mdl)->set_image(image);
  ((PluginModelCanvas*)mdl)->create_selectable_pixmap(*image->get_pixmap());
  ((PluginModelCanvas*)mdl)->set_label(canvas);  
  operator ()();

  emit set_canvas_image_label(((PluginModelCanvas*)mdl)->get_label());
}

bool controller::operator ()() {  
  emit update_inform();
  return true;
}
