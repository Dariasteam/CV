#include "menu.h"

menu::menu(QWidget *parent) : view_interface(parent)
{
  QBoxLayout* layout = new QBoxLayout (QBoxLayout::TopToBottom, this);
  setLayout(layout);
}
