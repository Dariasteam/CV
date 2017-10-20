#include "plugin_template.h"

plugin_template::plugin_template() {  
  meta_info = {"blanco y negro", "core"};

  menu* aux_menu = new menu();
  view = aux_menu;
  operation* op1 = new operation();
  op = op1;

  aux_menu->connect(aux_menu->get_pal_bttn(),&QPushButton::toggled,op1,&operation::on_change_pal);
}

