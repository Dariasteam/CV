#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, image_canvas* canvas) {
  mdl->set_image(image);
  mdl->create_selectable_pixmap(canvas->pixmap());
  operator ()();
}

bool controller::operator ()() {
  model->restore_backup();
  picture* img = model->get_image();  


  model-> = new selectable_pixmap (*img->get_pixmap());

  img->set_pixmap(s_pix);

  emit update_inform();
  return true;
}
