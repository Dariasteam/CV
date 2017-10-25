#include "canvas_image_label.h"

canvas_image_label::canvas_image_label(QPixmap& pixmap, QWidget *parent) :
  QFrame(parent)
{  
  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  img_canvas = new image_canvas (pixmap, this);
  set_canvas(img_canvas);
  setMouseTracking(true);  
  setMaximumSize(pixmap.size());
}

void canvas_image_label::set_canvas(image_canvas *img_c) {
  layout->removeWidget(img_canvas);
  img_canvas = img_c;
  layout->addWidget(img_c);
}

void canvas_image_label::mouseMoveEvent(QMouseEvent* ev) {
  update_coordenates(ev->pos());    
}
