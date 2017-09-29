#include "view.h"

view::view(QWidget *parent) : QWidget(parent) {


}

#include <QDebug>


void view::on_window_set_active(unsigned ac) {
  active_canvas = ac;
}



void view::add_canvas_window(QPixmap &pixmap) {
  canvas_window* aux_canvas = new canvas_window(canvas_list.size(), pixmap, this);

  canvas_list.push_back(aux_canvas);
  connect(canvas_list.back(),SIGNAL(set_active(unsigned)),this,SLOT(on_window_set_active(unsigned)));
  aux_canvas->show();
}

