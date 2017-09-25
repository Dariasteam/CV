#include "view.h"

view::view(QWidget *parent) : QWidget(parent) {

  canvas_list.push_back(new canvas_window(this));



}
