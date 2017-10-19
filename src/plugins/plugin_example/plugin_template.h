#ifndef PLUGIN_TEMPLATE_H
#define PLUGIN_TEMPLATE_H

#include "../../controller/plugin_interface.h"
#include "menu.h"

class plugin_template : public abstract_plugin {
private:
  const std::vector<double> NTSC = { 0.299, 0.587, 0.114 };
  const std::vector<double> PAL  = { 0.222, 0.707, 0.071 };

public:
  plugin_template ();
};

#endif

