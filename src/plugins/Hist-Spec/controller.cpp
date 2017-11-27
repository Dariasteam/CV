#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{
  connect(((menu*)mn)->request_picture_bttn,SIGNAL(pressed()),this,SLOT(on_bttn_request_pushed()));
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_lut(lut);
  mdl->set_image(image);
  ((model*)mdl)->a_lut.fill_from_histogram(image->get_histograms());
}

#include <iostream>

bool controller::operator ()() {  

  mdl->restore_backup();
  picture* img = mdl->get_image();

  LUT* lut = mdl->get_lut();

  lut->each_value_modificator_r([&](double i) -> double {          
    unsigned value = ((model*)mdl)->a_lut.r[i];
    return ((model*)mdl)->b_lut.search_value_r(value, i);
  });

  lut->each_value_modificator_g([&](double i) -> double {
    unsigned value = ((model*)mdl)->a_lut.g[i];
    return ((model*)mdl)->b_lut.search_value_g(value, i);
  });

  lut->each_value_modificator_b([&](double i) -> double {
    unsigned value = ((model*)mdl)->a_lut.b[i];
    return ((model*)mdl)->b_lut.search_value_b(value, i);
  });

  img->apply_lut(lut);

  emit update_inform();
  return true;
}


void controller::on_bttn_request_pushed() {
  emit request_current_image();
}

void controller::on_receive_current_image(picture *pic) {
  ((model*)mdl)->b_lut.fill_from_histogram(pic->get_histograms());
  operator ()();
}
