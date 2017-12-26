#include "menu.h"

menu::menu(QWidget *parent) : view_interface(parent)
{

  QBoxLayout* layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
  setLayout(layout);

  spin_rotate = new QSpinBox(this);
  spin_rotate->setMaximum(359);
  spin_rotate->setMinimum(-359);
  spin_rotate->setValue(0);

  slider_rotate = new QSlider(Qt::Horizontal, this);
  slider_rotate->setMaximum(359);
  slider_rotate->setMinimum(-359);
  slider_rotate->setValue(0);

  layout->addWidget(spin_rotate);
  layout->addWidget(slider_rotate);

  connect(spin_rotate,SIGNAL(valueChanged(int)),slider_rotate,SLOT(setValue(int)));
  connect(slider_rotate,SIGNAL(valueChanged(int)),spin_rotate,SLOT(setValue(int)));
}


