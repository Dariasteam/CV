#include "canvas_image_label.h"

canvas_image_label::canvas_image_label(QPixmap& pixmap, QWidget *parent) :
  QLabel(parent),
  selecting (false),
  area_selected (false)
{
  setMouseTracking(true);
  setPixmap(pixmap);
  setMaximumSize(pixmap.size());
}

void canvas_image_label::mousePressEvent(QMouseEvent *ev) {
  start_point = ev->pos();
  selecting = true;
}

void canvas_image_label::mouseReleaseEvent(QMouseEvent *ev) {
  end_point = ev->pos();
  selecting = false;
}

void canvas_image_label::mouseMoveEvent(QMouseEvent* ev) {
  update_coordenates(ev->pos());    
  if (selecting) {
    area_selected = true;
    end_point = ev->pos();
    repaint();
  }
}

void canvas_image_label::paintEvent(QPaintEvent *ev) {
  QPainter painter(this);
  painter.drawPixmap(0, 0, *pixmap());
  /*
  if (area_selected) {
    QRect rect (start_point, end_point);
    painter.drawRect(rect);
  }
  */
}
