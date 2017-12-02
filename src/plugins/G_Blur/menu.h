#ifndef MENU_H
#define MENU_H

#include <iostream>

#include <QWidget>
#include <QSlider>
#include <QBoxLayout>
#include <QLabel>
#include <QCheckBox>

#include "../../model/picture.h"

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class menu : public view_interface {  
  Q_OBJECT
private:
  QBoxLayout* layout;    
public:
  explicit menu(QWidget *parent = nullptr);      
};

#endif // MENU_H

