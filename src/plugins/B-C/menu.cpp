#include "menu.h"

menu::menu(QWidget *parent) :
  view_interface(parent)
{
  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  setLayout(layout);

  brightness_sliders = new slider_group (R_TEXT, G_TEXT, B_TEXT,
                                         MIN_RANGE_B, MAX_RANGE_B, DEFAULT_B);

  contrast_sliders   = new slider_group (R_TEXT, G_TEXT, B_TEXT,
                                         MIN_RANGE_C, MAX_RANGE_C, DEFAULT_C);

  fixed_checkbox = new QCheckBox (FIXED_TEXT, this);
  connect(fixed_checkbox,SIGNAL(toggled(bool)),this,SLOT(on_set_fixed(bool)));

  layout->addWidget(fixed_checkbox);

  layout->setMargin(0);
  layout->setSpacing(0);

  layout->addWidget(new QLabel(BRIGHTNESS_TXT, this));
  layout->addWidget(brightness_sliders);

  layout->addWidget(new QLabel(CONTRAST_TXT, this));
  layout->addWidget(contrast_sliders);  
}

