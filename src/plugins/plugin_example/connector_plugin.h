#ifndef ECHOPLUGIN_H
#define ECHOPLUGIN_H

#include <QObject>
#include <QtPlugin>

#include "../../controller/plugin_interface.h"
#include "../../model/picture.h"
#include "menu.h"

class conector_plugin : public QObject, PluginInterface {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "P")
  Q_INTERFACES(PluginInterface)  
private:
  const std::vector<double> NTSC = { 0.299, 0.587, 0.114 };
  const std::vector<double> PAL  = { 0.222, 0.707, 0.071 };
  bool pal;
public:
  conector_plugin ();
  bool operator () (picture* image);
  bool operator () ();
signals:
  void image_updated ();
public slots:
  void on_change_pal (bool p);
};

#endif

