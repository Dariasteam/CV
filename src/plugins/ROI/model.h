#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QPainter>

#include <iostream>

class selectable_pixmap : public QPixmap {
public:
  explicit selectable_pixmap (QPixmap& pix);
private:
  QPoint start_point;
  QPoint end_point;

  bool selecting;
  bool area_selected;

  void mouseMoveEvent(QMouseEvent* ev);
  void mousePressEvent(QMouseEvent *ev);
  void mouseReleaseEvent(QMouseEvent *ev);
  void paintEvent(QPaintEvent* ev);
signals:
  void update_region (QPoint, QPoint);
};

class model : public PluginModel {
public:
  model();
};

#endif // MODEL_H
