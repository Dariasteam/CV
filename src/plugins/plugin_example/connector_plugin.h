#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>

#include <iostream>

#include "../../controller/plugin_interface.h"

#include "plugin_template.h"

class conector_plugin : public QObject, PluginInterface {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "P")
  Q_INTERFACES(PluginInterface)
public:
  conector_plugin ();
};

#endif

