#include "canvas_image_label.h"

canvas_image_label::canvas_image_label(QPixmap& pixmap, QWidget *parent) : QLabel(parent)
{
  setMouseTracking(true);
  setPixmap(pixmap);
  setMaximumSize(pixmap.size());
}

void canvas_image_label::mouseMoveEvent(QMouseEvent* ev) {
  update_coordinates(ev->pos());
}
