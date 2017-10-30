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

class point_representation : public QWidget {
  Q_OBJECT
private:
  QBoxLayout* layout;

  QSpinBox* x;
  QSpinBox* y;

  QPushButton* close_bttn;
public:
  explicit point_representation (unsigned X, unsigned Y,
                                 QWidget* parent = nullptr);
public slots:
  void on_set_values (unsigned x, unsigned y);
signals:
  void check_values (unsigned x, unsigned y);
};

class model : public QObject,
              public PluginModel {
  Q_OBJECT
private:  
public:
  model();  
  QList <QPoint*> points;
  //QList <point_representation*> info_wids;
  QPoint* current_point;
  QPoint* prev;
  QPoint* next;
public slots:
  void on_update_point (QPoint original_c, double factor);  
  void on_click_point (QPoint point, double factor);
  void on_release_point ();
signals:
  void update_chart (QList<QPoint*>);
};

#endif // MODEL_H
