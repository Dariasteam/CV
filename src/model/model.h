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
  QList<picture*> image_list;  
  QList<abstract_plugin*> plugin_list;
  QList<image_operation*> operations;
  unsigned active_window;
public:
  model();

  void load_image (const QString&);
  void store_image (const QString&, unsigned i);
  void delete_imagepix_at (unsigned i);

  inline unsigned add_plugin (abstract_plugin* plugin) {
    plugin_list.push_back(plugin);
    return plugin_list.size() - 1;
  }

  inline const QList<abstract_plugin*>& get_plugins () { return plugin_list; }

  picture* get_picture_at (int i);
};

#endif // MODEL_H
