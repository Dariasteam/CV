#include "plugin_contoller.h"

plugin_controller::plugin_controller(operation_options_widget* op_wid) :
  op_widget (op_wid)
{

  connect (op_widget->get_apply(),&QPushButton::clicked,
           this, &plugin_controller::on_apply);

  connect (op_widget->get_cancel(),&QPushButton::clicked,
           this, &plugin_controller::on_cancel);

  connect (op_widget->get_overwrite(),&QCheckBox::toggled,
           this, &plugin_controller::on_overwrite_toggled);

  connect (op_widget->get_preview(),&QCheckBox::toggled,
           this, &plugin_controller::on_preview_toggled);

}

bool plugin_controller::operator ()(canvas_window* canvas,
                                    PluginInterface* op,
                                    picture* pic) {
  current_operation = op;
  current_canvas = canvas;
  current_pic = pic;  

  connect (((view_interface*)op->get_view()),SIGNAL(update_inform()),this,SLOT(update_view()));

  connect(((view_interface*)op->get_view()),&view_interface::update_inform,this,&plugin_controller::update_view);

  old_pixmap = new QPixmap(*pic->get_pixmap());

  if (!op->operator ()(pic)) return false;
/*
  result_pixmap = pic->get_pixmap();

  preview = op_widget->get_preview()->isChecked();
  overwrite = op_widget->get_overwrite()->isChecked();

  update_view(true);
  */
}

#include <iostream>

void plugin_controller::update_view() {
  std::cout << "UPDATE" << std::endl;
  /*
  if (preview) {
    current_canvas->set_pixmap(result_pixmap);
  } else {
    current_canvas->set_pixmap(old_pixmap);
  }
  current_canvas->update();
  */
}

void plugin_controller::on_apply(bool b) {
}

void plugin_controller::on_cancel(bool b) {

}

void plugin_controller::on_overwrite_toggled(bool b) {
  overwrite = b;
  update_view();
}

void plugin_controller::on_preview_toggled(bool b) {
  preview = b;
  update_view();
}

