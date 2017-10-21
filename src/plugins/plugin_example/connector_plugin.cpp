#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () :
  pal (true)
{
  meta_info = {"Blanco y negro", "core", false, false, true};
  view = new menu();
  connect ((menu*)view,SIGNAL(pal(bool)),(conector_plugin*)this,SLOT(on_change_pal(bool)));
  connect (this,SIGNAL(operation_finished()),(menu*)view,SLOT(op_finished()));

  //view->connect ((menu*)view,&menu::pal,this,&conector_plugin::on_change_pal);
}

bool conector_plugin::operator ()(picture* image) {  
  backup_image = image->make_copy();
  original_image = image;
  return operator ()();
}

bool conector_plugin::operator ()() {

  original_image->copy_from(backup_image);

  if (original_image == nullptr) return false;
  std::vector<double> transform;

  if (pal)
    transform = PAL;
  else
    transform = NTSC;

  original_image->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = pixel.red()   * transform[0] +
                    pixel.green() * transform[1] +
                    pixel.blue()  * transform[2];
    return QColor(gray, gray, gray);
  });

  original_image->set_black_and_white(true);
  emit operation_finished();

  return true;  
}

void conector_plugin::close() {
  delete backup_image;
  original_image = nullptr;
  backup_image = nullptr;
}

void conector_plugin::on_change_pal(bool p) {
  pal = p;
  operator ()();
}

