#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {  
  meta_info = {
  /* name            */  "Espejar verticalmente",
  /* category        */  "Editar",
  /* can_work_no_gui */  true,
  /* is_no_gui       */  true,
  /* can preview     */  true,
  /* require_lut     */  false,
  /* require_canvas  */  false,
  /* can overwrite   */  true,
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
