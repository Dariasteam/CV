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

class filter_a {
private:
  std::vector <std::vector <int>> kernel;
public:
  filter_a(std::vector<std::vector<int>> k) : kernel (k) {}

  inline unsigned get_size () const { return kernel.size(); }
  inline int get_element (unsigned i, unsigned j) const {
    if (i > kernel.size())
      i = 0;
    if (j > kernel.size())
      j = 0;
    return kernel[i][j];
  }
  static filter* generate_filter (std::vector<std::vector<int>> k) {
    return new filter (k);
  }
};

class menu : public view_interface {  
  Q_OBJECT
private:
  QBoxLayout* layout;    
public:
  explicit menu(QWidget *parent = nullptr);      
};

#endif // MENU_H

