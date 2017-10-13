#include "controller.h"

controller::controller() {
  main_window.show();

  connect(&main_window, SIGNAL(load_image(QString)),SLOT(on_load_image(QString)));
  connect(&main_window, SIGNAL(save_image(QString, unsigned)),SLOT(on_store_image(QString, unsigned)));
  connect(main_window.get_view(), SIGNAL(delete_image(uint)), this, SLOT(on_close_image(uint)));
  connect(main_window.get_view(), SIGNAL(image_focused(uint)), this, SLOT(on_set_active_image(uint)));

  connect(this, SIGNAL(update_histograms(histogram)),
          main_window.get_options_dock()->get_histogram_wid(),SLOT(update_charts(histogram)));
}

void controller::on_load_image(QString file_name) {
  mdl.load_image(file_name);  
  main_window.get_view()->add_canvas_window(* (mdl.get_picture_at(-1)->get_pixmap()), file_name);
}

void controller::on_store_image(QString file_name, unsigned id) {
  mdl.store_image(file_name, id);
}

void controller::on_close_image() {
  mdl.delete_imagepix_at(active_image);
}

#include <iostream>

void controller::on_set_active_image (unsigned id) {  
  active_image = id;

  emit update_histograms(mdl.get_picture_at(id)->get_histograms());
}
