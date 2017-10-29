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
  virtual bool operator () (picture* image, LUT* lut) = 0;
  virtual bool operator () (picture* image, canvas_image_label* canvas) = 0;
signals:
  virtual void update_inform () = 0;
  virtual void set_canvas_image_label (QLabel*) = 0;
};

class controller : public plugin_controller {
  Q_OBJECT
private:
public:
  bool operator () ();  
  virtual bool operator () (picture* image, LUT* lut) {}
  virtual bool operator () (picture* image, canvas_image_label* canvas);
  controller (QWidget* mn, PluginModel* mdl);
public slots:
  void on_set_region (QRect);
signals:
  void update_inform ();
  void set_canvas_image_label (QLabel*);
};

#endif // CONTROLLER_H
