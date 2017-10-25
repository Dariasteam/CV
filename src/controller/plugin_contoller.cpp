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

bool plugin_controller::operator ()(canvas_window* canvas,
                                    PluginInterface* op,
                                    picture* pic) {
  current_operation = op;
  current_canvas = canvas;
  backup_pic = pic->make_copy();
  backup_canvas = canvas->get_content();

  connect ((PluginController*)op->get_controller(),SIGNAL(update_inform()),
           this,SLOT(update_view()));

  connect((PluginController*)op->get_controller(),
          SIGNAL(set_canvas_image_label(QLabel*)),this,
          SLOT(on_change_image_label(QLabel*)));

  modified_pic = pic;  


  plugin_metainfo info = op->get_meta_info();

  LUT* lut = new LUT;
  if (info.require_lut) {
    if (((PluginController*)op->get_controller())
        ->operator ()(pic, lut)) return false;
  } else if (info.require_image_canvas) {
    if (((PluginController*)op->get_controller())
      ->operator ()(pic, current_canvas->get_content())) return false;
  }

  preview = op->get_meta_info().can_preview;
  overwrite = op->get_meta_info().can_overwrite;

  if (!preview) {
    op_widget->get_preview()->setChecked(false);
    op_widget->get_preview()->setCheckable(false);
  } else {
    op_widget->get_preview()->setCheckable(true);
  }

  if (!overwrite) {
    op_widget->get_overwrite()->setChecked(false);
    op_widget->get_overwrite()->setCheckable(false);
  } else {
    op_widget->get_overwrite()->setCheckable(true);
  }

  update_view();
}

void plugin_controller::update_view() {  
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
  if (overwrite) {
    current_canvas->set_pixmap(modified_pic->get_pixmap());
  } else {
    current_canvas->set_content(backup_canvas);
    current_canvas->set_pixmap(backup_pic->get_pixmap());
    picture* aux_pic = modified_pic;

    //modified_pic->restore_from(backup_pic);
    emit generate_image(aux_pic);
  }  
  on_end();
}

void plugin_controller::on_cancel(bool b) {
  modified_pic->restore_from(backup_pic);
  current_canvas->set_pixmap(backup_pic->get_pixmap());  
  current_canvas->set_content(backup_canvas);
  //delete modified_canvas;
  emit update_histogram(backup_pic->get_histograms());
  emit update_basic_info(backup_pic->get_basic_info());
  on_end();
}

void plugin_controller::on_end() {
  disconnect((view_interface*)current_operation->get_view(),SIGNAL(update_inform()),this,SLOT(update_view()));
  delete backup_pic;
  op_widget->on_clear_widget();
  current_canvas = nullptr;

  if (modified_canvas != nullptr)
    delete modified_canvas;

  modified_canvas = nullptr;

  current_operation->uninstance();

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

void plugin_controller::on_change_image_label(QLabel *canv) {
  modified_canvas = (canvas_image_label*)canv;
  modified_canvas->setPixmap(*backup_canvas->pixmap());
  current_canvas->set_content((canvas_image_label*)canv);

  connect (current_canvas->get_content(),SIGNAL(update_coordenates(QPoint)),
           foot,SLOT(on_update_coordenate_labels(QPoint)));
}

