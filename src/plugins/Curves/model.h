#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"
#include "../../view/canvas_image_label.h"

#include <iostream>

#include <QSpinBox>
#include <QPushButton>
#include <QWidget>

#define DEPTH 256
#define DISTANCE 40


class SyncPoint : public QObject, public QPoint {
  Q_OBJECT
public:
  explicit SyncPoint (int X, int Y) : QPoint(X,Y) {}
  SyncPoint (QPoint p) :
    QPoint(p.x(),p.y())
  {}
  SyncPoint (SyncPoint& p) :
    QPoint(p.x(),p.y())
  {}


  void setY (unsigned i) { QPoint::setY(i); }
  void setX (unsigned i) { QPoint::setX(i); }
public slots:
  void on_update_position (unsigned x, unsigned y) {
    setX (x);
    setY (y);
  }
};


class model : public QObject,
              public PluginModel {
  Q_OBJECT
private:  
public:
  model();  
  QList <SyncPoint*> points;
  //QList <point_representation*> info_wids;
  SyncPoint* current_point;
  SyncPoint* prev;
  SyncPoint* next;
public slots:
  void on_update_point (QPoint original_c, double factor);  
  void on_click_point (QPoint point, double factor);
  void on_release_point ();
signals:
  void update_chart (QList<SyncPoint*>);
};

#endif // MODEL_H
