#include "view.h"

view::view(QWidget *parent) : QWidget(parent) {  
  active_canvas = -1;
}

void view::on_window_set_active(unsigned id) {
  active_canvas = id;
}

void view::on_windows_close(unsigned id) {
  canvas_list.removeAt(id);
  if (canvas_list.size() < 0) {
    active_canvas = 0;
    canvas_list[0]->setFocus();
  } else {
    active_canvas = -1;
  }
  emit delete_image(id);
}

void view::add_canvas_window(QPixmap &pixmap) {
  canvas_window* aux_canvas = new canvas_window(canvas_list.size(), pixmap, this);
  canvas_list.push_back(aux_canvas);
  connect(canvas_list.back(),SIGNAL(set_active(unsigned)),this,SLOT(on_window_set_active(unsigned)));
  connect(canvas_list.back(),SIGNAL(close(uint)),this,SLOT(on_windows_close(uint)));
  aux_canvas->show();
}

