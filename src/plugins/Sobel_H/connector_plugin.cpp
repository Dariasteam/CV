#include <QtWidgets>

#include "connector_plugin.h"

conector_plugin::conector_plugin () {
  meta_info = {
  /* name            */  "Sobel horizontal",
  /* category        */  "Filtro",
  /* can_work_no_gui */  false,
  /* is_no_gui       */  false,
  /* can preview     */  true,
  /* require_lut     */  false,
  /* require_canvas  */  false
  };
}

void conector_plugin::close() {
  disconnect ((menu*)view,SIGNAL(pal(bool)),(conector_plugin*)this,SLOT(on_change_pal(bool)));
}

void conector_plugin::instance() {  
  if (view == nullptr && mdl == nullptr && ctrller == nullptr) {        
    view = new menu();        
    mdl = new model ();    
    ctrller = new controller(view, mdl);
  }
}
