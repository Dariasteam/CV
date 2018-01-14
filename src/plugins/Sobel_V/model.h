#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"

class filter_a {
private:
  std::vector <std::vector <int>> kernel;
public:
  filter_a(std::vector<std::vector<int>> k) : kernel (k) {}

  inline unsigned get_size () const { return kernel.size(); }
  inline int get_element (unsigned i, unsigned j) const {
    if (i > kernel.size())
      i = 0;
    if (j > kernel.size())
      j = 0;
    return kernel[i][j];
  }
  static filter* generate_filter (std::vector<std::vector<int>> k) {
    return new filter (k);
  }
};


class model : public PluginModel {
public:
  model();
};

#endif // MODEL_H
