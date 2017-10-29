#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#define DEPTH 256

#include <math.h>

#include "menu.h"
#include "model.h"
#include "../../controller/plugin_interface.h"
#include "../../model/lut.h"
#include "../../view/canvas_image_label.h"

class plugin_controller : public QObject {
  Q_OBJECT
protected:
  QWidget* view;
  PluginModel* model;
public:
  plugin_controller (QWidget* vw, PluginModel* mdl) :
    view (vw),
    model (mdl)
  {
    connect ((view_interface*)view,SIGNAL(update_inform()),this,SIGNAL(update_inform()));
  }    
  virtual bool operator () (picture* image, LUT* lut, canvas_image_label* canvas) = 0;
signals:
  virtual void update_inform () = 0;
  virtual void set_canvas_image_label (QLabel*) = 0;
};

class controller : public plugin_controller {
  Q_OBJECT
private:
public:
  bool operator () ();    
  virtual bool operator () (picture* image, LUT* lut, canvas_image_label* canvas);
  controller (QWidget* mn, PluginModel* mdl);
signals:
  void update_inform ();
  void set_canvas_image_label (QLabel*);
};

#endif // CONTROLLER_H
