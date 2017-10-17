#include <QtWidgets>

#include "connector_plugin.h"
#include "plugin_template.h"

conector_plugin::conector_plugin () {
  //content = nullptr;
  content = new plugin_template;
}
