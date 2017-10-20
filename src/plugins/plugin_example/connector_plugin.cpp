#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () :
  pal (true)
{
  meta_info = {"Blanco y negro", "core", false, false, true};
  view = new menu();
}

bool conector_plugin::operator ()(picture* image) {
  std::vector<double> transform;

  if (pal)
    transform = PAL;
  else
    transform = NTSC;

  image->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = pixel.red()   * transform[0] +
                    pixel.green() * transform[1] +
                    pixel.blue()  * transform[2];

    return QColor(gray, gray, gray);
  });
  image->set_black_and_white(true);
  return true;
}

void conector_plugin::on_change_pal(bool p) {
  pal = p;
}
