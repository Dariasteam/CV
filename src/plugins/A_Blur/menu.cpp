#include "menu.h"

menu::menu(QWidget *parent) :
  view_interface(parent)
{
  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  setLayout(layout);

  slider = new labeled_slider;

  layout->setMargin(0);
  layout->setSpacing(0);

  layout->addWidget(new QLabel(GAMMA_TXT, this));
  layout->addWidget(slider);
}
