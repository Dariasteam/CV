#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{
  QSlider* s = ((menu*)mn)->slider->get_slider();
  connect(s,SIGNAL(sliderReleased()),this,SLOT(on_slider_moved()));
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) { 
  mdl->set_image(image);
  picture* img = mdl->get_image();

  operator ()();
}

bool controller::operator ()() {    

  mdl->restore_backup();
  picture* img = mdl->get_image();
  unsigned value = ((menu*)view)->slider->get_slider()->value();

  filter_a* fil = ((model*)mdl)->generate_filter(value);

  img->apply_filter((filter*)fil);

  emit update_inform();
  return true;
}
