#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>
#include <QPushButton>
#include <QWidget>
#include <QBoxLayout>

#include <iostream>

#include "../../controller/plugin_connector.h"
#include "plugin_template.h"

class PluginA : public QObject, PluginInterface {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "P")
    Q_INTERFACES(PluginInterface)  
public:
  PluginA () { content = new plugin_template; }

};

#endif
