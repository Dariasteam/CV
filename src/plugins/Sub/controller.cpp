#include "controller.h"

controller::controller(QWidget *mn, PluginModel* mdl) :
  plugin_controller (mn, mdl)
{
  connect(((menu*)mn)->request_picture_bttn,SIGNAL(pressed()),this,SLOT(on_bttn_request_pushed()));
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_lut(lut);
  mdl->set_image(image);  
}

bool controller::operator ()() {  
  mdl->restore_backup();

  picture* img_a = mdl->get_image();
  picture* img_b = ((model*)mdl)->aux_pic;

  unsigned height_a = img_a->get_size().height();
  unsigned width_a  = img_a->get_size().width();

  unsigned height_b = img_b->get_size().height();
  unsigned width_b  = img_b->get_size().width();

  if (height_a != height_b || width_a != width_b)
    return false;

  img_a->subImage(img_b);

  emit update_inform();
  return true;

  /*
  for (unsigned i = 0; i < height_a; i++) {
    for (unsigned j = 0; j < width_a; j++) {

    }
  }


  LUT* lut = mdl->get_lut();

  lut->each_value_modificator_r([&](double i) -> double {          
    unsigned value = ((model*)mdl)->a_lut.r[i];
    return ((model*)mdl)->b_lut.search_value_r(value, i);
  });

  lut->each_value_modificator_g([&](double i) -> double {
    unsigned value = ((model*)mdl)->a_lut.g[i];
    return ((model*)mdl)->b_lut.search_value_g(value, i);
  });

  lut->each_value_modificator_b([&](double i) -> double {
    unsigned value = ((model*)mdl)->a_lut.b[i];
    return ((model*)mdl)->b_lut.search_value_b(value, i);
  });

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned r = std::round(lut->r [pixel.red()  ]);
    unsigned g = std::round(lut->g [pixel.green()]);
    unsigned b = std::round(lut->b [pixel.blue() ]);
    return QColor(r, g, b);
  });


  */
}


void controller::on_bttn_request_pushed() {
  emit request_current_image();
}

void controller::on_receive_current_image(picture *pic) {
  ((model*)mdl)->aux_pic = pic;
  operator ()();
}
