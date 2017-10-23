#include "controller.h"

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl),
  pal (true)
{}

bool controller::operator () (picture* image, LUT* lut) {
  model->set_lut(lut);
  model->set_image(image); 

  operator ()();
}

bool controller::operator ()() {
  model->restore_backup();
  picture* img = model->get_image();
  std::vector<double> transform;

  //picture* p = new picture(img);

  if (pal)
    transform = PAL;
  else
    transform = NTSC;

  LUT* lut = model->get_lut();

  lut->each_value_modificator_r([&](double i) -> double {
    return i * transform[0];
  });

  lut->each_value_modificator_g([&](double i) {
    return i * transform[1];
  });

  lut->each_value_modificator_b([&](double i) {
    return i * transform[2];
  });

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = lut->r [pixel.red()  ] +
                    lut->g [pixel.green()] +
                    lut->b [pixel.blue()];
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
