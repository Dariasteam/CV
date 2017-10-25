#ifndef CANVAS_IMAGE_LABEL_H
#define CANVAS_IMAGE_LABEL_H

#include <QLabel>
#include <QFrame>
#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QBoxLayout>
#include <QPainter>

#include "../model/picture.h"

class canvas_image_label : public QLabel {
  Q_OBJECT
public:
  explicit canvas_image_label(QPixmap& pixmap, QWidget *parent = nullptr);
private:
  void mouseMoveEvent(QMouseEvent *ev);
signals:
  void update_coordenates (QPoint);
};

#endif // CANVAS_IMAGE_LABEL_H
