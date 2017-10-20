#ifndef PLUGIN_CONTOLLER_H
#define PLUGIN_CONTOLLER_H

#include <QPixmap>
#include <QImage>
#include <QObject>

#include "../view/canvas_window.h"
#include "../view/operation_options_widget.h"
#include "../model/picture.h"
#include "plugin_interface.h"
#include "../plugins/plugin_example/menu.h"


class plugin_controller : public QObject {
  Q_OBJECT
private:
  bool overwrite;
  bool apply;
  bool preview;

  operation_options_widget* op_widget;
  PluginInterface* current_operation;
  canvas_window* current_canvas;
  picture* current_pic;
  QPixmap* result_pixmap;
  QPixmap* old_pixmap;
public:
  plugin_controller(operation_options_widget* op_wid);

  bool operator()(canvas_window* canvas,
                  PluginInterface* op,
                  picture* pic);

public slots:

  void on_preview_toggled (bool);
  void on_overwrite_toggled (bool);
  void on_apply (bool);
  void on_cancel (bool);

signals:
private slots:
  void update_view (bool);
};

#endif // PLUGIN_CONTOLLER_H
