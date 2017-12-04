#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{}

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

  ((model*)mdl)->brightness = old_b;
  ((model*)mdl)->contrast = old_c;

  ((menu*)view)->set_slider_b(old_b);
  ((menu*)view)->set_slider_c(old_c);

  connect(((menu*)view)->get_contrast_values(),SIGNAL(update_values(rgb_float_values)),
          this,SLOT(on_change_contrast(rgb_float_values)));

  connect(((menu*)view)->get_bright_values(),SIGNAL(update_values(rgb_float_values)),
          this,SLOT(on_change_brightness(rgb_float_values)));
}

bool controller::operator ()() {  
  mdl->restore_backup();
  picture* img = mdl->get_image();

  LUT* lut = mdl->get_lut();

  rgb_float_values alpha = ((model*)mdl)->contrast / ((model*)mdl)->old_contrast;
  rgb_float_values beta = ((model*)mdl)->brightness - alpha * ((model*)mdl)->old_brightness;

// RED
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

  img->apply_lut(lut);

  emit update_inform();
  return true;
}

void controller::on_change_brightness(rgb_float_values rgb) {
  ((model*)mdl)->brightness = rgb;
  operator ()();
}

void controller::on_change_contrast  (rgb_float_values rgb) {
  ((model*)mdl)->contrast = rgb;
  operator ()();
}
