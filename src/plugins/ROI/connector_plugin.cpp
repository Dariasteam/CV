#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {
  meta_info = {"Seleccionar área de interés", "core", false, false, false};
}

void conector_plugin::close() {  
}

void conector_plugin::instance() {  
  if (view == nullptr && mdl == nullptr && ctrller == nullptr) {        
    view = new menu();        
    mdl = new model ();    
    ctrller = new controller(view, mdl);        
  }
}
