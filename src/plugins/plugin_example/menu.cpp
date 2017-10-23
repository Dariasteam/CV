#include "menu.h"

menu::menu(QWidget *parent) : view_interface(parent)
{
  QBoxLayout* layout = new QBoxLayout (QBoxLayout::TopToBottom, this);
  setLayout(layout);

  bttn_PAL = new QPushButton (PAL_TXT, this);
  bttn_NTSC = new QPushButton (NTSC_TXT, this);

  bttn_PAL->setCheckable(true);
  bttn_NTSC->setCheckable(true);

  bttn_PAL->setChecked(true);

  layout->addWidget(bttn_NTSC);
  layout->addWidget(bttn_PAL);

  connect (bttn_PAL,&QPushButton::clicked,this,&menu::set_pal_checked);
  connect (bttn_NTSC,&QPushButton::clicked,this,&menu::set_ntsc_checked);

  emit pal(true);
}

void menu::set_ntsc_checked(bool) {
  bttn_PAL->setChecked(false);
  emit pal (false);  
}

void menu::set_pal_checked(bool) {
  bttn_NTSC->setChecked(false);
  emit pal (true);
}
