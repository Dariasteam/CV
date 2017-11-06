#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{
  connect(((menu*)mn)->request_picture_bttn,SIGNAL(pressed()),this,SLOT(on_bttn_request_pushed()));
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_lut(lut);
  mdl->set_image(image);
  ((model*)mdl)->a_lut.fill_from_histogram(image->get_histograms());
}

bool controller::operator ()() {
  mdl->restore_backup();
  picture* img = mdl->get_image();

  LUT* lut = mdl->get_lut();

  lut->each_value_modificator_r([&](double i) -> double {      
    double c = img->get_histograms().normalized_acumulated_r [unsigned(i)];
    return std::max(c * DEPTH -1, double(0));
  });

  lut->each_value_modificator_g([&](double i) -> double {
    double c = img->get_histograms().normalized_acumulated_g [unsigned(i)];
    return std::max(c * DEPTH -1, double(0));
  });

  lut->each_value_modificator_b([&](double i) -> double {
    double c = img->get_histograms().normalized_acumulated_b [unsigned(i)];
    return std::max(c * DEPTH -1, double(0));
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


void controller::generate_lut_a() {

}

void controller::generate_lut_b() {

}

void controller::on_bttn_request_pushed() {
  emit request_current_image();
}

#include <iostream>

void controller::on_receive_current_image(picture *pic) {
  ((model*)mdl)->b_lut.fill_from_histogram(mdl->get_image()->get_histograms());


  pic->get_histograms();
  operator ()();
}
