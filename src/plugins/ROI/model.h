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
#include <QLabel>
#include <QObject>

#include <iostream>

class ImageCanvas : public QLabel {
  Q_OBJECT
public:
  ImageCanvas (QPixmap& pix, QWidget* parent = nullptr) :
    QLabel (parent)
  {
    setPixmap(pix);
  }
};

class selectable_pixmap : public ImageCanvas {
  Q_OBJECT
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
};



class model : public PluginModelCanvas {
private:

public:
  model();
  virtual void create_selectable_pixmap(QPixmap& pix) {
    slct_pixmap = (image_canvas*)new selectable_pixmap (pix);
  }
};

#endif // MODEL_H
