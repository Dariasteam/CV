#include "view.h"

view::view(footer* fot, QWidget *parent) : QWidget(parent) {
  active_canvas = -1;
  foot = fot;
}

void view::on_window_set_active(unsigned key) {
  emit image_focused(key);
  canvas_list.find(key).value()->raise();
  active_canvas = key;
}

void view::on_windows_close(unsigned key) {
  auto it = canvas_list.find(key);
  if (it == canvas_list.end()) return;

  canvas_window* aux = it.value();
  canvas_list.remove(key);
  //delete aux;
  if (canvas_list.size() > 0) {
    active_canvas = canvas_list.begin().key();
    canvas_list.begin().value()->setFocus();
  } else {    
    emit no_image_focused();
    active_canvas = -1;
  }
  emit delete_image();
}

void view::add_canvas_window(QPixmap &pixmap, QString name) {
  QPoint position (-20, -20);
  if (canvas_list.size() > 0)
    position = canvas_list[active_canvas]->pos();

  unsigned key = canvas_list.size();
  canvas_window* aux_canvas = new canvas_window(key, pixmap, foot, name, this);  
  canvas_list.insert(key,aux_canvas);

  connect(aux_canvas,SIGNAL(set_active(unsigned)),this,SLOT(on_window_set_active(unsigned)));
  connect(aux_canvas,SIGNAL(close(uint)),this,SLOT(on_windows_close(uint)));

  aux_canvas->move(position + QPoint(20,20));
  aux_canvas->show();

}

canvas_window* view::get_active_canvas() {
  if (active_canvas > -1 )
    return canvas_list.find(active_canvas).value();
  else
    return nullptr;
}
