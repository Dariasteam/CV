#ifndef MODEL_H
#define MODEL_H

#include "../../model/picture.h"
#include "../../controller/plugin_interface.h"

#include <QPixmap>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QPainter>
#include <QLabel>
#include <QObject>

#include <iostream>

class model : public PluginModel {
public:
  int width;
  int height;
public:
  model();
};

#endif // MODEL_H
