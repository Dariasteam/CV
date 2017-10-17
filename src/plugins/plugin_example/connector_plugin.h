#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>

#include <iostream>

#include "../../controller/plugin_connector.h"

class plugin_template : public plugin {
public:
  plugin_template ();
};

class conector_plugin : public QObject, PluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "P")
    Q_INTERFACES(PluginInterface)
public:
  conector_plugin ();
  
};

#endif

