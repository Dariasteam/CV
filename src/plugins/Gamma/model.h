#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"


class custom_LUT {
public:
  std::vector<double> r;
  std::vector<double> g;
  std::vector<double> b;

  custom_LUT () :
    r (DEPTH),
    g (DEPTH),
    b (DEPTH)
  {
    for (unsigned i = 0; i < DEPTH; i++) {
      r[i] = double(i) / double(DEPTH - 1);
      g[i] = double(i) / double(DEPTH - 1);
      b[i] = double(i) / double(DEPTH - 1);
    }
  }
};

class model : public PluginModel {
public:
  double gamma;
  custom_LUT c_lut;
public:
  model();
};

#endif // MODEL_H
