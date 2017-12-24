#include "plugin_contoller.h"

plugin_controller::plugin_controller(operation_options_widget* op_wid, footer* fot) :
  op_widget (op_wid),
  modified_pic (nullptr),
  backup_pic (nullptr),
  current_canvas (nullptr),
  current_operation (nullptr),
  foot (fot)
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

#include <iostream>

bool plugin_controller::operator ()(canvas_window* canvas,
                                    PluginInterface* op,
                                    picture* pic) {

  current_operation = op;
  current_canvas = canvas;  
  backup_canvas = canvas->get_content();


  backup_pic = new picture (pic);
  modified_pic = pic;

  connect(modified_pic,SIGNAL(update_progress(int)),foot,SLOT(on_update_progress_bar(int)));

  connect ((PluginController*)op->get_controller(),SIGNAL(update_inform()),
           this,SLOT(update_view()));

  connect((PluginController*)op->get_controller(),
          SIGNAL(set_canvas_image_label(QLabel*)),this,
          SLOT(on_change_image_label(QLabel*)));  

  connect((PluginController*)op->get_controller(),
          SIGNAL(request_current_image()),this,
          SLOT(on_request_current_image()));

  connect(this,SIGNAL(send_current_image(void*)),
          (PluginController*)op->get_controller(),
          SLOT(on_receive_current_image(void*)));

  plugin_metainfo info = op->get_meta_info();

  preview = op->get_meta_info().can_preview;
  overwrite = op->get_meta_info().can_overwrite;

  if (!preview) {
    op_widget->get_preview()->setChecked(false);
    op_widget->get_preview()->setCheckable(false);
  } else {    
    op_widget->get_preview()->setCheckable(true);
    op_widget->get_preview()->setChecked(true);
  }

  if (!overwrite) {
    op_widget->get_overwrite()->setChecked(false);
    op_widget->get_overwrite()->setCheckable(false);
  } else {
    op_widget->get_overwrite()->setCheckable(true);
    op_widget->get_overwrite()->setChecked(true);
  }

  LUT* lut = new LUT;
  if (((PluginController*)op->get_controller())->operator ()
      (modified_pic, lut, current_canvas->get_content())) return false;
}

void plugin_controller::update_view() {
  foot->on_reset_progress_bar();
  if (preview) {
    current_canvas->set_pixmap(modified_pic->get_pixmap());
    emit update_histogram(modified_pic->get_histograms());
    emit update_basic_info(modified_pic->get_basic_info());
  } else {
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    emit update_histogram(backup_pic->get_histograms());
    emit update_basic_info(backup_pic->get_basic_info());
  }
  current_canvas->update();
}

void plugin_controller::on_apply(bool b) {
  current_canvas->set_content(backup_canvas);
  if (overwrite) {
    current_canvas->set_pixmap(modified_pic->get_pixmap());
  } else {
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    emit generate_image(modified_pic->make_copy());
    modified_pic->restore_from(backup_pic);
  }   
  on_end();
}

void plugin_controller::on_cancel(bool b) {
  modified_pic->restore_from(backup_pic);
  current_canvas->set_pixmap(backup_pic->get_pixmap());  
  current_canvas->set_content(backup_canvas);  
  emit update_histogram(backup_pic->get_histograms());
  emit update_basic_info(backup_pic->get_basic_info());
  on_end();
}

void plugin_controller::on_end() {
  disconnect(modified_pic,SIGNAL(update_progress(int)),foot,SLOT(on_update_progress_bar(int)));
  disconnect((view_interface*)current_operation->get_view(),SIGNAL(update_inform()),this,SLOT(update_view()));

  delete backup_pic;
  op_widget->on_clear_widget();
  current_canvas = nullptr;

  if (modified_canvas != nullptr)
    delete modified_canvas;
  modified_canvas = nullptr;

  //on_clear();

  current_operation = nullptr;
  backup_pic = nullptr;
  modified_pic = nullptr;    
}

void plugin_controller::on_clear() {
  if (modified_pic != nullptr && backup_pic != nullptr && current_canvas != nullptr) {
    modified_pic->restore_from(backup_pic);
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    delete backup_pic;
  }

  op_widget->on_clear_widget();
  if (current_operation != nullptr)
    current_operation->uninstance();
}

void plugin_controller::on_overwrite_toggled(bool b) {
  overwrite = b;  
}

void plugin_controller::on_preview_toggled(bool b) {
  preview = b;
  update_view();
}

void plugin_controller::on_request_current_image() {  
  emit request_current_image();
}

void plugin_controller::on_receive_current_image(picture* pic ) {    
  emit send_current_image((void*)pic);
}

void plugin_controller::on_change_image_label(QLabel *canv) {
  modified_canvas = (canvas_image_label*)canv;
  modified_canvas->setPixmap(*backup_canvas->pixmap());
  current_canvas->set_content((canvas_image_label*)canv);

  connect (current_canvas->get_content(),SIGNAL(update_coordenates(QPoint)),
           foot,SLOT(on_update_coordenate_labels(QPoint)));
}

