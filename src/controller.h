#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>


#include "mainwindow.h"
#include "view.h"
#include "model.h"
#include "histogram.h"

class controller : public QObject {
  Q_OBJECT
private:
  MainWindow main_window;
  model mdl;
  short active_image;
public:
  controller();
public slots:
  void on_load_image (QString file_name);
  void on_store_image (QString file_name, unsigned id);
  void on_close_image ();
  void on_set_active_image (unsigned image);
signals:
  void update_histograms (histogram hist);
};

#endif // CONTROLLER_H
