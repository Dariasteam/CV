#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* lbl) {
  model->set_lut(lut);
  model->set_image(image); 

  operator ()();
}

bool controller::operator ()() {
  model->restore_backup();
  picture* img = model->get_image();  

  selectable_pixmap* s_pix = new selectable_pixmap (*img->get_pixmap());

  img->set_pixmap(s_pix);

  emit update_inform();
  return true;
}
