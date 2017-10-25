#include "canvas_image_label.h"

canvas_image_label::canvas_image_label(QPixmap& pixmap, QWidget *parent) :
  QLabel(parent)
{    
  /*
  img_canvas = new image_canvas (pixmap, this);
  set_canvas(img_canvas);
  */
  setPixmap(pixmap);
  setMouseTracking(true);
  setMaximumSize(pixmap.size());
}

void canvas_image_label::mouseMoveEvent(QMouseEvent* ev) {
  update_coordenates(ev->pos());    
}
