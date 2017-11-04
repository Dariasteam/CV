#include "controller.h"

#include <iostream>

controller::controller(QWidget *mn, PluginModel *mdl) :
  plugin_controller (mn, mdl)
{
  connect((menu*)mn,SIGNAL(update_lut(QList<SyncPoint*>)),
          this,SLOT(on_calculate_lut(QList<SyncPoint*>)));
}

bool controller::operator () (picture* image, LUT* lut, canvas_image_label* canvas) {
  mdl->set_lut(lut);
  mdl->set_image(image);
}

bool controller::operator ()() {
  mdl->restore_backup();
  picture* img = mdl->get_image();

  LUT* lut = mdl->get_lut();

  img->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned r = lut->r [pixel.red()  ];
    unsigned g = lut->g [pixel.green()];
    unsigned b = lut->b [pixel.blue() ];
    return QColor(r, g, b);
  });

  emit update_inform();
  return true;
}

void controller::on_calculate_lut(QList<SyncPoint*> points) {
  for (unsigned i = 1; i < points.size(); i++) {
    SyncPoint* aP = points.at(i - 1);
    SyncPoint* bP = points.at(i);

    double b = bP->y() - aP->y();
    double c = bP->x() - aP->x();
    double b_c = b / c;

    for (unsigned j = aP->x(); j < bP->x(); j++) {
      mdl->get_lut()->each_modificator_from_to(aP->x(), bP->x(), [&] (double value) {
        double a = value - aP->x();
        double result = a * b_c + aP->y();
        return result;
      });

    }

  }

  operator ()();
}
