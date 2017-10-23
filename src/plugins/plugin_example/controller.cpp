#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl),
  pal (true)
{}

bool controller::operator () (picture* image) {
  model->set_image(image);
  operator ()();
}

bool controller::operator ()() {
  model->restore_backup();
  picture* img = model->get_image();
  std::vector<double> transform;

  if (pal)
    transform = PAL;
  else
    transform = NTSC;

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = pixel.red()   * transform[0] +
                    pixel.green() * transform[1] +
                    pixel.blue()  * transform[2];
    return QColor(gray, gray, gray);
  });

  img->set_black_and_white(true);  
  emit update_inform();
  return true;
}

void controller::on_change_pal(bool p) {  
  pal = p;
  operator ()();
}
