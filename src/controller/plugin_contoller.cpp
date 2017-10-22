#include "plugin_contoller.h"

plugin_controller::plugin_controller(operation_options_widget* op_wid) :
  op_widget (op_wid),
  modified_pic (nullptr),
  backup_pic (nullptr),
  current_canvas (nullptr)
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
  backup_pic = pic->make_copy();

  // No sé cual de los dos es el que funciona
  connect (((view_interface*)op->get_view()),SIGNAL(update_inform()),this,SLOT(update_view()));
  connect(((view_interface*)op->get_view()),&view_interface::update_inform,this,&plugin_controller::update_view);  

  modified_pic = pic;

  if (!op->operator ()(pic)) return false;

  preview = op_widget->get_preview()->isChecked();
  overwrite = op_widget->get_overwrite()->isChecked();  

  update_view();
}

void plugin_controller::update_view() {  
  if (preview) {
    current_canvas->set_pixmap(modified_pic->get_pixmap());
    emit update_histogram(modified_pic->get_histograms());
  } else {
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    emit update_histogram(backup_pic->get_histograms());
  }
  current_canvas->update();
}

void plugin_controller::on_apply(bool b) {
  if (overwrite) {
    current_canvas->set_pixmap(modified_pic->get_pixmap());
  } else {
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    picture* aux_pic = modified_pic->make_copy();
    modified_pic->copy_from(backup_pic);
    emit generate_image(aux_pic);
  }
  current_operation->close();
  on_end();
}

void plugin_controller::on_cancel(bool b) {
  modified_pic->copy_from(backup_pic);
  current_canvas->set_pixmap(backup_pic->get_pixmap());
  current_operation->close();
  emit update_histogram(backup_pic->get_histograms());
  on_end();
}

void plugin_controller::on_end() {
  disconnect((view_interface*)current_operation->get_view(),SIGNAL(update_inform()),this,SLOT(update_view()));
  delete backup_pic;
  op_widget->on_clear_widget();
  current_canvas = nullptr;
  current_operation->close();
  current_operation = nullptr;
  backup_pic = nullptr;
  modified_pic = nullptr;
}

void plugin_controller::on_clear() {
  if (modified_pic != nullptr && backup_pic != nullptr && current_canvas != nullptr) {
    modified_pic->copy_from(backup_pic);
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    delete backup_pic;
  }
  op_widget->on_clear_widget();
  //on_end();
}

void plugin_controller::on_overwrite_toggled(bool b) {
  overwrite = b;  
}

void plugin_controller::on_preview_toggled(bool b) {
  preview = b;
  update_view();
}

