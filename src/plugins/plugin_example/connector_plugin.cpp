#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () :
  pal (true)
{
  meta_info = {"Blanco y negro", "core", false, false, true};
  view = new menu();

  view->connect ((menu*)view,SIGNAL(pal(bool)),(conector_plugin*)this,SLOT(on_change_pal(bool)));
  view->connect ((menu*)view,&menu::pal,this,&conector_plugin::on_change_pal);
}

bool conector_plugin::operator ()(picture* image) {
  pic = image;
  return operator ()();
}

bool conector_plugin::operator ()() {

  if (pic == nullptr) return false;
  std::vector<double> transform;

  if (pal)
    transform = PAL;
  else
    transform = NTSC;

  pic->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = pixel.red()   * transform[0] +
                    pixel.green() * transform[1] +
                    pixel.blue()  * transform[2];
    return QColor(gray, gray, gray);
  });

  pic->set_black_and_white(true);
  return true;

  emit image_updated();
}

void conector_plugin::on_change_pal(bool p) {
  pal = p;
}

