#include "controller.h"

controller::controller() {
  main_window.show();

  connect(&main_window, SIGNAL(load_image(QString)),SLOT(on_load_image(QString)));
  connect(&main_window, SIGNAL(save_image(QString, unsigned)),SLOT(on_store_image(QString, unsigned)));
  connect(main_window.get_view(), SIGNAL(delete_image(uint)), this, SLOT(on_close_image(uint)));
  connect(main_window.get_view(), SIGNAL(image_focused(uint)), this, SLOT(on_set_active_image(uint)));

  connect(this, SIGNAL(update_histograms(histogram)),
          main_window.get_options_dock()->get_histogram_wid(),SLOT(update_charts(histogram)));

  load_all_plugins(DEFAULT_PLUGINS_LOCATION);
}

void controller::on_load_image(const QString& file_name) {
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
  emit update_histograms(mdl.get_picture_at(id)->get_histograms());
}

bool controller::load_all_plugins (const QString& path) {
  QDir pluginsDir(qApp->applicationDirPath());
  pluginsDir.cd(path);  
  bool result = true;
  foreach (QString fileName, pluginsDir.entryList(QDir::Files)) {
    std::cout << "Tratando de cargar " << fileName.toStdString() << " | ";
    QPluginLoader pluginLoader(pluginsDir.absoluteFilePath(fileName));
    QObject *plugin = pluginLoader.instance();
    if (plugin) {
      std::cout << "plugin cargado correctamente";
      PluginInterface* aux = qobject_cast<PluginInterface *>(plugin);
      mdl.add_plugin(aux);
      plugin_metainfo info = aux->get_plugin()->get_meta_info();
      main_window.on_add_plugin(info.category, info.name);
    } else {
      std::cout << "No se ha podido cargar" << std::endl;
      result = false;
    }
    std::cout << "\n";
  }
  return result;
}

bool controller::load_plugin (const QString& path) {

}
