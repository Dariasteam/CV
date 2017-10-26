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

  if (image->is_black_and_white()) {
    QCheckBox* chk = ((menu*)view)->get_fixed_checkbox();
    chk->setChecked(true);
    chk->setEnabled(false);
  }

  on_change_brightness(DEFAULT_B, DEFAULT_B, DEFAULT_B);
  on_change_contrast(DEFAULT_C, DEFAULT_C, DEFAULT_C);
  operator ()();
}

bool controller::operator ()() {  
  ((PluginModelLut*)mdl)->restore_backup();
  picture* img = ((PluginModelLut*)mdl)->get_image();

  LUT* lut = ((PluginModelLut*)mdl)->get_lut();

// RED

  rgb_float_values beta = ((model*)mdl)->brightness;
  rgb_float_values alpha = ((model*)mdl)->contrast;

  lut->each_value_modificator_r([&](double i) -> double {
    return alpha.r * i + beta.r - 1;
  });

// GREEN
  lut->each_value_modificator_g([&](double i) -> double {
    return alpha.g * i + beta.g - 1;
  });

// BLUE
  lut->each_value_modificator_b([&](double i) -> double {
    return alpha.b * i + beta.b - 1;
  });

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
  ((model*)mdl)->brightness = {
    double(r) / 10,
    double(g) / 10,
    double(b) / 10
  };
  operator ()();
}

void controller::on_change_contrast  (int r, int g, int b) {
  ((model*)mdl)->contrast = {
    double(r) / 10,
    double(g) / 10,
    double(b) / 10
  };
  operator ()();
}
