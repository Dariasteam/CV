#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {  
  meta_info = {
  /* name            */  "Ajuste lineal por tramos",
  /* category        */  "core",
  /* can_work_no_gui */  false,
  /* is_no_gui       */  false,
  /* can preview     */  true,
  /* require_lut     */  true,
  /* require_canvas  */  true,
  /* can overwrite   */  true,
  };
}

void conector_plugin::close() {  

}

void conector_plugin::instance() {  
  if (view == nullptr && mdl == nullptr && ctrller == nullptr) {        
    mdl = new model ();
    view = new menu((model*)mdl);
    ctrller = new controller(view, mdl);        
  }
}
