#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {
  meta_info = {"Blanco y negro", "core", false, false, true};
}

void conector_plugin::close() {
  disconnect ((menu*)view,SIGNAL(pal(bool)),(conector_plugin*)this,SLOT(on_change_pal(bool)));
}

void conector_plugin::instance() {
  if (view == nullptr && mdl == nullptr && ctrller == nullptr) {
    view = new menu();
    mdl = new model ();
    ctrller = new controller(view, mdl);
    connect((menu*)view,&menu::pal,(controller*)ctrller,&controller::on_change_pal);
  }
}
