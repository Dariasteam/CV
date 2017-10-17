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
#include "../controller/plugin_connector.h"

using namespace std;

class model {
private:
  QList<picture*> image_list;  
  QList<PluginInterface*> plugin_list;
  unsigned active_window;
public:
  model();

  void load_image (const QString&);
  void store_image (const QString&, unsigned i);
  void delete_imagepix_at (unsigned i);

  void add_plugin (PluginInterface* plugin) { plugin_list.push_back(plugin); }

  picture* get_picture_at (int i);
};

#endif // MODEL_H
