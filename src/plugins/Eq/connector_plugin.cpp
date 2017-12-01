#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {
  meta_info = {
  /* name            */  "Ecualizar",
  /* category        */  "Operaciones no lineales",
  /* can_work_no_gui */  true,
  /* is_no_gui       */  false,
  /* can preview     */  true,
  /* require_lut     */  true,
  /* require_canvas  */  false
  };
}

void conector_plugin::close() {}

void conector_plugin::instance() {  
  if (view == nullptr && mdl == nullptr && ctrller == nullptr) {        
    view = new menu();        
    mdl = new model ();    
    ctrller = new controller(view, mdl);    
  }
}
