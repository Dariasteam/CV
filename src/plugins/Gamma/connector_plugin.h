#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "../../controller/plugin_interface.h"
#include "menu.h"
#include "controller.h"
#include "model.h"

class conector_plugin : public QObject, PluginInterface {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "P")
  Q_INTERFACES(PluginInterface)
public:
  conector_plugin ();    
  void close ();
  void instance ();
};

#endif

