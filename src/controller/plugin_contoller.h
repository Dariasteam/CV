#ifndef PLUGIN_CONTOLLER_H
#define PLUGIN_CONTOLLER_H

#include <QPixmap>
#include <QImage>
#include <QObject>

#include "../view/canvas_image_label.h"
#include "../view/canvas_window.h"
#include "../view/operation_options_widget.h"
#include "../view/footer.h"
#include "../model/picture.h"
#include "plugin_interface.h"
#include "view_interface.h"

class plugin_controller : public QObject {
  Q_OBJECT
private:
  bool overwrite;
  bool apply;
  bool preview;

  footer* foot;

  operation_options_widget* op_widget;
  PluginInterface* current_operation;
  canvas_window* current_canvas;

  picture* backup_pic;
  picture* modified_pic;  

  canvas_image_label* backup_canvas;
  canvas_image_label* modified_canvas;    
public:
  plugin_controller(operation_options_widget* op_wid, footer* foot);

  bool operator()(canvas_window* canvas,
                  PluginInterface* op,
                  picture* pic);

public slots:

  void on_preview_toggled (bool);
  void on_overwrite_toggled (bool);
  void on_apply (bool);
  void on_cancel (bool);
  void on_end ();
  void on_clear ();
  void on_receive_current_image (picture*);
  void on_request_current_image ();
signals:
  void update_histogram(histogram);
  void update_basic_info(picture_basic_info);
  void overwrite_image(picture*);
  void generate_image(picture*);
  void send_current_image (void*);
  void request_current_image ();
private slots:
  void update_view ();
  void on_change_image_label (QLabel* canv);    
};

#endif // PLUGIN_CONTOLLER_H
