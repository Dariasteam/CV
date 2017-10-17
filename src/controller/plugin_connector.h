#ifndef PLUGIN_CONNECTOR_H
#define PLUGIN_CONNECTOR_H

#include <QString>
#include <QWidget>

struct plugin_metainfo {
  QString name     = "default plugin name";
  QString category = "default plugin category";
};

class plugin {
protected:
  // Información para los menús
  plugin_metainfo meta_info;
  // Contenido
  QWidget* view;
public:
  const plugin_metainfo& get_meta_info () { return meta_info; }
  QWidget* get_view ()                    { return view;      }
};

class PluginInterface {
protected:
  plugin* content;
public:
  virtual ~PluginInterface() {}
  plugin* get_plugin () { return content; }
};

#define PluginInterface_iid "P"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGIN_CONNECTOR_H
