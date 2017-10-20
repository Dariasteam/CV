#ifndef PLUGIN_CONNECTOR_H
#define PLUGIN_CONNECTOR_H

#include <QString>
#include <QWidget>

#include "../model/picture.h"

struct plugin_metainfo {
  QString name     = "default plugin name";
  QString category = "default plugin category";
  bool can_work_without_gui = false;
  bool no_gui = false;
  bool can_preview = false;
};

class M : public QWidget {
  Q_OBJECT
public:
  M (QWidget* parent) : QWidget (parent) {}
signals:
  virtual void update_inform () = 0;
};

class PluginInterface {
protected:
  // Información para los menús
  plugin_metainfo meta_info;
  // Contenido
  QWidget* view;
  picture* pic;
public:
  PluginInterface () : pic (nullptr) {}
  const plugin_metainfo& get_meta_info () { return meta_info; }
  QWidget* get_view ()                    { return view;      }
  bool operator () (picture* image) {}
  bool operator () () {}
  void set_picture (picture* image) { pic = image; }
};

#define PluginInterface_iid "P"

Q_DECLARE_INTERFACE(PluginInterface, PluginInterface_iid)

#endif // PLUGIN_CONNECTOR_H
