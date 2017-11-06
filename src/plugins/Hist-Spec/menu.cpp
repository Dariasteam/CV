#include "menu.h"

menu::menu(QWidget *parent) : view_interface(parent)
{
  QBoxLayout* layout = new QBoxLayout (QBoxLayout::TopToBottom, this);
  setLayout(layout);
  request_picture_bttn = new QPushButton (REQUEST_TXT);
  layout->addWidget(request_picture_bttn);
}
