#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>

#include "mainwindow.h"
#include "view.h"
#include "model.h"

class controller : public QObject {
  Q_OBJECT
private:
  MainWindow main_window;

  model mdl;
public:
  controller();
public slots:
  void on_load_image (QString file_name);
  void on_store_image (QString file_name);
};

#endif // CONTROLLER_H
