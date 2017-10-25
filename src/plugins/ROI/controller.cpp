#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, canvas_image_label* canvas) {

  ((PluginModelCanvas*)mdl)->set_image(image);

  ((PluginModelCanvas*)mdl)->create_selectable_pixmap(*image->get_pixmap());
  ((PluginModelCanvas*)mdl)->set_label(canvas);

  ((PluginModelCanvas*)mdl)->get_label()
      ->set_canvas(((PluginModelCanvas*)mdl)->get_selectable_pixmap());
  operator ()();
}

bool controller::operator ()() {
  mdl->restore_backup();
  emit update_inform();
  return true;
}
