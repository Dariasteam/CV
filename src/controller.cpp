#include "controller.h"

controller::controller() {
  main_window.show();

  connect(&main_window, SIGNAL(load_image(QString)),SLOT(on_load_image(QString)));
  connect(&main_window, SIGNAL(save_image(QString, unsigned)),SLOT(on_store_image(QString, unsigned)));
  connect(main_window.get_view(), SIGNAL(delete_image(uint)), this, SLOT(on_close_image(uint)));
}

void controller::on_load_image(QString file_name) {
  mdl.load_image(file_name);
  main_window.get_view()->add_canvas_window(*mdl.get_pixmap_at(-1), file_name);
}

void controller::on_store_image(QString file_name, unsigned id) {
  mdl.store_image(file_name, id);
}

void controller::on_close_image(unsigned id) {
  mdl.delete_imagepix_at(id);
}

