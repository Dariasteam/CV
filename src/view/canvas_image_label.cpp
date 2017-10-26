#include "canvas_image_label.h"

canvas_image_label::canvas_image_label(QPixmap& pixmap, QWidget *parent) :
  QLabel(parent)
{    
  setPixmap(pixmap);
  setMouseTracking(true);
  setMaximumSize(pixmap.size());
}

void canvas_image_label::mouseMoveEvent(QMouseEvent* ev) {
  emit update_coordenates(ev->pos());
}
