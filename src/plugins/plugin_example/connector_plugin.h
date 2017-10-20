#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "../../controller/plugin_interface.h"
#include "../../model/picture.h"

#include "plugin_template.h"

class conector_plugin : public QObject, PluginInterface {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "P")
  Q_INTERFACES(PluginInterface)
public:
  conector_plugin ();
};

#endif

