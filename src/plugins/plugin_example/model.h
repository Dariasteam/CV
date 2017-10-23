#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"

class plugin_model {
private:
  picture* backup_image;
  picture* original_image;
public:
  plugin_model () :
    backup_image (nullptr),
    original_image (nullptr)
  {}
  void set_image (picture* pic) {
    backup_image = pic->make_copy();
    original_image = pic;
  }
  picture* get_image () { return original_image; }
  void restore_backup () { original_image->restore_from(backup_image); }
};


class model : public PluginModel
{
public:
  model();
};

#endif // MODEL_H
