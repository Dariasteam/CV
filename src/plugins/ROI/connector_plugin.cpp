#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {  
  meta_info = {
  /* name            */  "Seleccionar área de interés",
  /* category        */  "Editar",
  /* can_work_no_gui */  false,
  /* is_no_gui       */  false,
  /* can preview     */  false,
  /* require_lut     */  false,
  /* require_canvas  */  true,
  /* can overwrite   */  false,
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
