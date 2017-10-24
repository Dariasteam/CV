#include "canvas_image_label.h"

canvas_image_label::canvas_image_label(QPixmap& pixmap, QWidget *parent) :
  QFrame(parent),
  selecting (false),
  area_selected (false)  
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
  layout->addWidget(img_canvas);
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
  //QPainter painter(this);
  //painter.drawPixmap(0, 0, *pixmap());
  /*
  if (area_selected) {
    QRect rect (start_point, end_point);
    painter.drawRect(rect);
  }
  */
}
