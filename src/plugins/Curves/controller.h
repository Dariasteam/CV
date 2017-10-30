#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "menu.h"
#include "model.h"
#include "../../controller/plugin_interface.h"
#include "../../model/lut.h"
#include "../../view/canvas_image_label.h"

class plugin_controller : public QObject {
  Q_OBJECT
protected:
  QWidget* view;
  PluginModel* mdl;
public:
  plugin_controller (QWidget* vw, PluginModel* ml) :
    view (vw),
    mdl (ml)
  {
    connect ((view_interface*)view,SIGNAL(update_inform()),this,SIGNAL(update_inform()));
  }  
  virtual bool operator () (picture* image, LUT* lut, canvas_image_label* canvas) = 0;
signals:
  virtual void update_inform () = 0;  
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
};

#endif // CONTROLLER_H
