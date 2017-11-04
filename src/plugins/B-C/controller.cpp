#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{
  connect(((menu*)mn)->get_bright_values(),SIGNAL(update_values(rgb_float_values)),
          this,SLOT(on_change_brightness(rgb_float_values)));

  connect(((menu*)mn)->get_contrast_values(),SIGNAL(update_values(rgb_float_values)),
          this,SLOT(on_change_contrast(rgb_float_values)));
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_lut(lut);
  mdl->set_image(image);
  picture* img = mdl->get_image();

  if (image->is_black_and_white()) {
    QCheckBox* chk = ((menu*)view)->get_fixed_checkbox();
    chk->setChecked(true);
    chk->setEnabled(false);
  }

  rgb_float_values old_b = image->get_basic_info().average;
  rgb_float_values old_c = image->get_basic_info().deviation;

  ((model*)mdl)->old_brightness = old_b;
  ((model*)mdl)->old_contrast = old_c;

  on_change_brightness(old_b);
  on_change_contrast(old_c);

  ((menu*)view)->set_slider_b(old_b);
  ((menu*)view)->set_slider_c(old_c);
  operator ()();
}

bool controller::operator ()() {  
  mdl->restore_backup();
  picture* img = mdl->get_image();

  LUT* lut = mdl->get_lut();

// RED  

  rgb_float_values alpha = ((model*)mdl)->contrast / ((model*)mdl)->old_contrast;
  rgb_float_values beta = ((model*)mdl)->brightness - alpha * ((model*)mdl)->old_brightness;

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

void controller::on_change_brightness(rgb_float_values rgb) {
  ((model*)mdl)->brightness = {
    double(rgb.r),
    double(rgb.g),
    double(rgb.b)
  };
  operator ()();
}

void controller::on_change_contrast  (rgb_float_values rgb) {
  ((model*)mdl)->contrast = {
    double(rgb.r),
    double(rgb.g),
    double(rgb.b)
  };
  operator ()();
}
