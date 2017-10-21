#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QFile>

#define DEFAULT_PLUGINS_LOCATION "../build/compiled_plugins/"

#include "../view/mainwindow.h"
#include "../view/view.h"
#include "../model/model.h"
#include "../model/histogram.h"
#include "plugin_interface.h"
#include "indexed_action.h"
#include "plugin_contoller.h"

class controller : public QObject {
  Q_OBJECT
private:
  MainWindow main_window;
  model mdl;
  short active_image;
  plugin_controller* plugin_ctrller;
public:
  controller();

public slots:
  void on_load_image (const QString& file_name);
  void on_store_image (const QString& file_name, unsigned id);
  void on_close_image ();
  void on_set_active_image (unsigned image);

  void on_create_image (picture* pic);
  void on_overwrite_image (picture* pic);

  bool load_all_plugins (const QString& path);
  bool load_plugin (const QString& plugin_name, const QDir& dir);
private slots:
  void use_plugin (unsigned index);  
signals:
  void update_histograms (histogram hist);
  void update_operation_option (QWidget* wid);
};

#endif // CONTROLLER_H
