#ifndef MODEL_H
#define MODEL_H

#include <QImage>
#include <QPixmap>
#include <QList>
#include <QImageReader>
#include <QList>

#include <iostream>

#include "picture.h"
#include "histogram.h"
#include "../controller/plugin_interface.h"

using namespace std;

class model {
private:
  QList<picture*> picture_list;  
  QList<PluginInterface*> plugin_list;
  unsigned active_picture;
public:
  model();

  void load_image (const QString&);
  void store_image (const QString&, unsigned i);
  void delete_imagepix_at (unsigned i);
  void add_image (picture* pic);
  bool replace_image (picture* pic);

  inline unsigned add_plugin (PluginInterface* plugin) {
    plugin_list.push_back(plugin);
    return plugin_list.size() - 1;
  }

  inline const QList<picture*>& get_pictures () { return picture_list; }
  inline const QList<PluginInterface*>& get_plugins () { return plugin_list; }

  picture* get_picture_at (int i);
};

#endif // MODEL_H
