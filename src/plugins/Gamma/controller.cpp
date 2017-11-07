#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{

  connect(((menu*)view)->gamma_s->get_slider(),&QSlider::valueChanged,
               this,&controller::on_change_gamma);
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_lut(lut);
  mdl->set_image(image);
  picture* img = mdl->get_image();  
}

bool controller::operator ()() {  
  mdl->restore_backup();
  picture* img = mdl->get_image();

  LUT* lut = mdl->get_lut();

// RED
  double gamma = ((model*)mdl)->gamma;

  lut->each_value_modificator_r([&](double i) -> double {
    return std::pow(((model*)mdl)->c_lut.r[i], gamma) * DEPTH - 1;
  });

// GREEN
  lut->each_value_modificator_g([&](double i) -> double {
    return std::pow(((model*)mdl)->c_lut.g[i], gamma) * DEPTH - 1;
  });

// BLUE
  lut->each_value_modificator_b([&](double i) -> double {
    return std::pow(((model*)mdl)->c_lut.b[i], gamma) * DEPTH - 1;
  });

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned r = lut->r [pixel.red()  ];
    unsigned g = lut->g [pixel.green()];
    unsigned b = lut->b [pixel.blue() ];
    return QColor(r, g, b);
  }); 

  emit update_inform();  
  return true;
}

void controller::on_change_gamma(int gamma) {
  ((model*)mdl)->gamma = double(gamma) / double(DEFAULT_VALUE / DIVISOR);
  operator ()();
}
