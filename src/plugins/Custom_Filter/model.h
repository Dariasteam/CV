#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"

class filter_a {
private:
  std::vector <std::vector <int>> kernel;
public:
  filter_a(std::vector<std::vector<int>> k) : kernel (k) {}

  inline unsigned get_y_size () const { return kernel.size(); }
  inline unsigned get_x_size () const { return kernel[0].size(); }

  inline int get_element (unsigned i, unsigned j) const {
    return kernel[i][j];
  }

};

class model : public PluginModel {
public:
  model();
  filter_a* generate_filter (std::vector<std::vector<int>> vec) {
    return new filter_a (vec);
  }

};

#endif // MODEL_H
