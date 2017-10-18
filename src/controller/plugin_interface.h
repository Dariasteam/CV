#ifndef PLUGIN_CONNECTOR_H
#define PLUGIN_CONNECTOR_H

#include <QString>
#include <QWidget>



struct plugin_metainfo {
  QString name     = "default plugin name";
  QString category = "default plugin category";
  bool can_work_without_gui = false;
  bool no_gui = false;
};

class image_operation {
  virtual bool operator () (QImage* image) = 0;
};

class abstract_plugin {
protected:
  // Información para los menúsr
  plugin_metainfo meta_info;
  // Contenido
  QWidget* view;
  image_operation* operation;
public:  
  const plugin_metainfo& get_meta_info () { return meta_info; }
  QWidget* get_view ()                    { return view;      }
};

class PluginInterface {
protected:
  abstract_plugin* content;
public:
  virtual ~PluginInterface() {}
  abstract_plugin* get_plugin () { return content; }
};

#define PluginInterface_iid "P"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGIN_CONNECTOR_H
