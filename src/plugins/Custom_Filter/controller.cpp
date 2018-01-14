#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{  
 connect((menu*)mn,SIGNAL(kernel_valid(std::vector<std::vector<int> >)),this,
         SLOT(on_custom_kernel_valid(std::vector<std::vector<int> >)));

}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) { 
  mdl->set_image(image);
  picture* img = mdl->get_image();

  operator ()();
}

bool controller::operator ()() {    


}

void controller::on_custom_kernel_valid (std::vector<std::vector<int>> vec) {
  mdl->restore_backup();
  picture* img = mdl->get_image();

  filter_a* fil = ((model*)mdl)->generate_filter(vec);

  img->apply_filter((filter*)fil);

  emit update_inform();
}
