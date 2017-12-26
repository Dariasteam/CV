#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <cmath>

#include "menu.h"
#include "model.h"
#include "../../controller/plugin_interface.h"

#define PI 3.14159

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
  bool use_bilinear;
  std::pair<double, double> direct_transformation (double x, double y, double ro);
  double max_x (std::vector<std::pair<double, double>>& vec);
  double max_y (std::vector<std::pair<double, double>>& vec);
  double min_x (std::vector<std::pair<double, double>>& vec);
  double min_y (std::vector<std::pair<double, double>>& vec);
  double to_rad (double angle);
public:  
  virtual bool operator () (picture* image, LUT* lut, canvas_image_label* canvas);
  bool operator ()(double w, double h);
  controller (QWidget* mn, PluginModel* mdl);    
public slots:
  void on_update_value (int);
signals:
  void update_inform ();
};

#endif // CONTROLLER_H
