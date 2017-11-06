#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../model/histogram.h"
#include "../../controller/plugin_interface.h"

class custom_LUT {
  std::vector<double> r;
  std::vector<double> g;
  std::vector<double> b;
public:

  void fill_from_histogram (const histogram& hist) {
    for (unsigned i = 0; i < r.size(); i++) {
      double c = hist.normalized_acumulated_r [unsigned(i)];
      r[i] = std::max(c * DEPTH -1, double(0));
    }

    for (unsigned i = 0; i < g.size(); i++) {
      double c = hist.normalized_acumulated_g [unsigned(i)];
      r[i] = std::max(c * DEPTH -1, double(0));
    }

    for (unsigned i = 0; i < b.size(); i++) {
      double c = hist.normalized_acumulated_b [unsigned(i)];
      r[i] = std::max(c * DEPTH -1, double(0));
    }
  }

  double search_value (double v, double original, std::vector<double>& vec) {
    unsigned distance = DEPTH + 1;
    double value = 0;
    for (unsigned i = 0; i < vec.size(); i++) {
      if (vec[i] == v && distance < abs(original - v)) {
        distance = abs(original - v);
        value = vec[i];
      }
    }
    return value;
  }

  double search_value_r (double v, double original) {
    return search_value(v, original, r);
  }

  double search_value_g (double v, double original) {
    return search_value(v, original, g);
  }

  double search_value_b (double v, double original) {
    return search_value(v, original, b);
  }
};

class model : public PluginModel {
public:
  picture* aux_pic;
  model();
  custom_LUT a_lut;
  custom_LUT b_lut;
};

#endif // MODEL_H
