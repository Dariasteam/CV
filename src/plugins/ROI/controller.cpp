#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, canvas_image_label* canvas) {

  ((PluginModelCanvas*)mdl)->set_image(image);
  ((PluginModelCanvas*)mdl)->create_selectable_pixmap(*image->get_pixmap());  
  //operator ()();

  connect (((selectable_pixmap*)((model*)mdl)->get_label()),
           &selectable_pixmap::update_region, this, &controller::on_set_region);

  emit set_canvas_image_label((QLabel*)((PluginModelCanvas*)mdl)->get_label());
}

bool controller::operator ()() {  
  emit update_inform();
  return true;
}

void controller::on_set_region(QRect rect) {
  if (rect.size().width() > 1 && rect.size().height() > 1) {
    mdl->restore_backup();
    QImage crop_img = mdl->get_image()->get_raw_image()->copy(rect);
    mdl->get_image()->restore_from(&crop_img);
  }
}
