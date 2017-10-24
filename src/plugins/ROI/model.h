#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"
#include "../../view/canvas_image_label.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QPainter>

#include <iostream>

class selectable_pixmap : public image_canvas {
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
  selectable_pixmap* slct_pixmap;
public:  
  inline selectable_pixmap* get_selectable_pixmap () { return slct_pixmap; }
  void create_selectable_pixmap (QPixmap& pix);
  model();
};

#endif // MODEL_H
