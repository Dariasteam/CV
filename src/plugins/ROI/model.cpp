#include "model.h"

model::model() {}

void model::create_selectable_pixmap(QPixmap &pix) {
  slct_pixmap = new selectable_pixmap (pix);
}

selectable_pixmap::selectable_pixmap(QPixmap& pix) :
  image_canvas(pix),
  selecting (false),
  area_selected (false)
{  
  QPixmap::operator =(pix);
}

void selectable_pixmap::mousePressEvent(QMouseEvent *ev) {
  start_point = ev->pos();
  selecting = true;
}

void selectable_pixmap::mouseReleaseEvent(QMouseEvent *ev) {
  end_point = ev->pos();
  selecting = false;
}

void selectable_pixmap::mouseMoveEvent(QMouseEvent *ev) {
  if (selecting) {
    area_selected = true;
    end_point = ev->pos();
  }
}

void selectable_pixmap::paintEvent(QPaintEvent *ev) {
  QPainter painter(this);

  //painter.drawPixmap(0, 0, );
  if (area_selected) {
    QRect rect (start_point, end_point);
    painter.drawRect(rect);
  }
}
