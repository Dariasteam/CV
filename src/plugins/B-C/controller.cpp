#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{
  connect(((menu*)mn)->get_bright_values(),SIGNAL(update_values(int,int,int)),
          this,SLOT(on_change_brightness(int,int,int)));

  connect(((menu*)mn)->get_contrast_values(),SIGNAL(update_values(int,int,int)),
          this,SLOT(on_change_contrast(int,int,int)));
}

bool controller::operator () (picture* image, LUT* lut) {
  ((PluginModelLut*)mdl)->set_lut(lut);
  ((PluginModelLut*)mdl)->set_image(image);
  picture* img = ((PluginModelLut*)mdl)->get_image();

  if (image->is_black_and_white())
    ((menu*)view)->set_fixed();

  ((model*)mdl)->average = img->get_basic_info().average;
}

bool controller::operator ()() {
  ((PluginModelLut*)mdl)->restore_backup();
  picture* img = ((PluginModelLut*)mdl)->get_image();

  LUT* lut = ((PluginModelLut*)mdl)->get_lut();

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned r = lut->r [pixel.red()  ];
    unsigned g = lut->g [pixel.green()];
    unsigned b = lut->b [pixel.blue() ];
    return QColor(r, g, b);
  });

  emit update_inform();
  return true;
}

void controller::on_change_brightness(int r, int g, int b) {
  LUT* lut = ((PluginModelLut*)mdl)->get_lut();
// RED
  if (r != ((model*)mdl)->brightness.r) {
    ((model*)mdl)->brightness.r = r;
    lut->each_value_modificator_r([&](double i) -> double {
      return i * ((model*)mdl)->brightness.r / ((model*)mdl)->average.r;
    });
  }
// GREEN
  if (g != ((model*)mdl)->brightness.g) {
    ((model*)mdl)->brightness.g = g;
    lut->each_value_modificator_g([&](double i) -> double {
      return i * ((model*)mdl)->brightness.g / ((model*)mdl)->average.g;
    });
  }
// BLUE
  if (b != ((model*)mdl)->brightness.b) {
    ((model*)mdl)->brightness.b = b;
    lut->each_value_modificator_b([&](double i) -> double {
      return i * ((model*)mdl)->brightness.b / ((model*)mdl)->average.b;
    });
  }

  operator ()();
}

void controller::on_change_contrast  (int r, int g, int b) {
  ((model*)mdl)->contrast = {r, g, b};
  operator ()();
}
