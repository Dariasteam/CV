#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"
#include "../../view/canvas_image_label.h"

#include <iostream>

#define DEPTH 256
#define DISTANCE 40

class model : public QObject,
              public PluginModel {
  Q_OBJECT
private:  
public:
  model();  
  QList <QPoint*> points;
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
