#include "menu.h"

menu::menu(QWidget *parent) : QWidget(parent)
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

  connect (bttn_PAL,SIGNAL(clicked(bool)), this, SLOT(set_pal_checked(bool)));
  connect (bttn_NTSC,SIGNAL(clicked(bool)), this, SLOT(set_ntsc_checked(bool)));
}


void menu::set_ntsc_checked(bool) {
  bttn_PAL->setChecked(false);
}

void menu::set_pal_checked(bool) {
  bttn_NTSC->setChecked(false);
}
