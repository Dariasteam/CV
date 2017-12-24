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
  PluginModel* mdl;
public:
  plugin_controller (QWidget* vw, PluginModel* mdl) :
    view (vw),
    mdl (mdl)
  {
    connect ((view_interface*)view,SIGNAL(update_inform()),this,SIGNAL(update_inform()));
  }    
  virtual bool operator () (picture* image, LUT* lut, canvas_image_label* canvas) = 0;
public slots:
  virtual void on_receive_current_image (void* pic) = 0;
};

class controller : public plugin_controller {
  Q_OBJECT
private:
public:
  bool operator () ();    
  virtual bool operator () (picture* image, LUT* lut, canvas_image_label* canvas);
  controller (QWidget* mn, PluginModel* mdl);
public slots:
  void on_receive_current_image (void* pic);
  void on_bttn_request_pushed();
signals:
  void update_inform ();
  void set_canvas_image_label (QLabel*);
  void request_current_image ();
};

#endif // CONTROLLER_H
