#include "controller.h"

controller::controller() {
  main_window.show();

  connect(&main_window, SIGNAL(load_image(QString)),SLOT(on_load_image(QString)));

  connect(&main_window, SIGNAL(save_image(QString)),SLOT(on_store_image(QString)));

}

#include <QDebug>

void controller::on_load_image(QString file_name) {
  mdl.load_image(file_name);
  main_window.get_view()->add_canvas_window(*mdl.get_pixmap_at(-1));
}

void controller::on_store_image(QString file_name) {

}
