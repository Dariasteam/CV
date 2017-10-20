#include "controller.h"

controller::controller() {
  main_window.show();

  connect(&main_window, SIGNAL(load_image(QString)),SLOT(on_load_image(QString)));
  connect(&main_window, SIGNAL(save_image(QString, unsigned)),SLOT(on_store_image(QString, unsigned)));
  connect(main_window.get_view(), SIGNAL(delete_image(uint)), this, SLOT(on_close_image(uint)));
  connect(main_window.get_view(), SIGNAL(image_focused(uint)), this, SLOT(on_set_active_image(uint)));

  connect(this, SIGNAL(update_histograms(histogram)),
          main_window.get_options_dock()->get_histogram_wid(),SLOT(on_update_charts(histogram)));

  connect(this, SIGNAL(update_operation_option(QWidget*)),
          main_window.get_options_dock()->get_operation_wid(), SLOT(on_set_widget(QWidget*)));

  plugin_ctrller = new plugin_controller (main_window.get_options_dock()->get_operation_wid());

  load_all_plugins(DEFAULT_PLUGINS_LOCATION);
}

void controller::on_load_image(const QString& file_name) {
  main_window.get_options_dock()->setEnabled(true);
  mdl.load_image(file_name);    
  main_window.get_view()->add_canvas_window(* (mdl.get_picture_at(-1)->get_pixmap()), file_name);
}

void controller::on_store_image(const QString& file_name, unsigned id) {
  mdl.store_image(file_name, id);
}

void controller::on_close_image() {
  mdl.delete_imagepix_at(active_image);
}

void controller::on_set_active_image (unsigned id) {
  active_image = id;   

  emit update_histograms(mdl.get_pictures().at(id)->get_histograms());
}

bool controller::load_all_plugins (const QString& path) {
  QDir pluginsDir(qApp->applicationDirPath());
  pluginsDir.cd(path);
  bool result = true;
  foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
    load_plugin(fileName, pluginsDir);
    std::cout << "\n";
  }
  return result;
}

bool controller::load_plugin (const QString& path, const QDir& dir) {

  QPluginLoader pluginLoader(dir.absoluteFilePath(path));
  QObject *plugin = pluginLoader.instance();
  std::cout << "Tratando de cargar " << path.toStdString() << " | ";

  if (!plugin) {
    std::cout << "No se ha podido cargar" << std::endl;
      return false;
  } else {
    std::cout << "plugin cargado correctamente";

    PluginInterface* aux = qobject_cast<PluginInterface *>(plugin);

    unsigned index = mdl.add_plugin(aux);
/*
    plugin_metainfo info = aux->get_meta_info();

    indexed_action* plugin_action = main_window.on_add_plugin(info.category, info.name, index);

    connect(plugin_action,SIGNAL(pressed_signal(uint)),this,SLOT(use_plugin(uint)));
*/
  }


}

void controller::on_create_image(picture *pic) {
  mdl.add_image(pic);
  main_window.get_view()->add_canvas_window(* (mdl.get_picture_at(-1)->get_pixmap()), "file_name");
}

void controller::use_plugin(unsigned index) {
  if (index < mdl.get_plugins().size() && index < mdl.get_pictures().size()) {
    PluginInterface* aux_plugin = mdl.get_plugins().at(index);
    //emit update_operation_option(aux_plugin->get_view());

    //picture* aux_pic = new picture (mdl.get_picture_at(index));

    //canvas_window* aux_canvas = main_window.get_view()->get_active_canvas();
/*
    plugin_ctrller->operator ()(aux_canvas,
                                aux_plugin,
                                aux_pic);
*/
    //aux_canvas->set_pixmap(aux_pic->get_pixmap());

    //emit update_histograms(aux_pic->get_histograms());
  }

}
