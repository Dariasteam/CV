#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {  
  meta_info = {
  /* name            */  "seleccionar área de interés",
  /* category        */  "core",
  /* can_work_no_gui */  false,
  /* is_no_gui       */  false,
  /* can preview     */  false,
  /* require_lut     */  false,
  /* require_canvas  */  true
  };
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
