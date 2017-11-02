#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"

class model : public PluginModel {
public:
  rgb_float_values brightness;
  rgb_float_values contrast;

  rgb_float_values old_brightness;
  rgb_float_values old_contrast;
public:
  model();
};

#endif // MODEL_H
