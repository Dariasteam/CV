#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{}

bool controller::operator () (picture* image, LUT* lut) {
  ((PluginModelLut*)model)->set_lut(lut);
  ((PluginModelLut*)model)->set_image(image);

  operator ()();
}

bool controller::operator ()() {
  ((PluginModelLut*)model)->restore_backup();
  picture* img = ((PluginModelLut*)model)->get_image();

  LUT* lut = ((PluginModelLut*)model)->get_lut();

  lut->each_value_modificator_r([&](double i) -> double {
    double c = img->get_histograms().normalized_acumulated_r [i];
    return std::max(c * DEPTH, double(0));
  });

  lut->each_value_modificator_g([&](double i) {
    double c = img->get_histograms().normalized_acumulated_g [i];
    return std::max(c * DEPTH, double(0));
  });

  lut->each_value_modificator_b([&](double i) {
    double c = img->get_histograms().normalized_acumulated_b [i];
    return std::max(c * DEPTH, double(0));
  });

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned r = lut->r [pixel.red()  ];
    unsigned g = lut->g [pixel.green()];
    unsigned b = lut->b [pixel.blue()];
    return QColor(r, g, b);
  });

  emit update_inform();
  return true;
}
