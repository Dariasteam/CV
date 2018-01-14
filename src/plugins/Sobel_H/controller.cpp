#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) { 
  mdl->set_image(image);
  picture* img = mdl->get_image();

  operator ()();
}

bool controller::operator ()() {  
  mdl->restore_backup();
  picture* img = mdl->get_image();  

  filter_a* fil = new filter_a ({
                {-1,0,1},
                {-2,0,2},
                {-1,0,1},
              });

  img->apply_filter((filter*)fil);

  emit update_inform();
  return true;
}

void controller::on_change_contrast (rgb_float_values rgb) {
  operator ()();
}
