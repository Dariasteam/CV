#include "histogram_widget.h"

histogram_widget::histogram_widget(QWidget *parent) :
  QWidget(parent)
{
  tabs = new QTabWidget (this);

  tabs->setMovable(false);
  tabs->setTabsClosable(false);

  layout = new QBoxLayout (QBoxLayout::TopToBottom, this);

  tabs->addTab(&chart_histogram, TAB1_NAME);
  tabs->addTab(&chart_ac_histogram, TAB2_NAME);
  layout->addWidget(tabs);

  QWidget* check_box_widget = new QWidget(this);
  QBoxLayout* check_box_layout = new QBoxLayout(QBoxLayout::LeftToRight);

  tabs->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);

  red_chkbox   = new QCheckBox (R_CHK_NAME, check_box_widget);
  green_chkbox = new QCheckBox (G_CHK_NAME, check_box_widget);
  blue_chkbox  = new QCheckBox (B_CHK_NAME, check_box_widget);

  red_chkbox->setChecked(true);
  green_chkbox->setChecked(true);
  blue_chkbox->setChecked(true);

  check_box_layout->addWidget(red_chkbox);
  check_box_layout->addWidget(green_chkbox);
  check_box_layout->addWidget(blue_chkbox);

  check_box_widget->setLayout(check_box_layout);

  layout->addWidget(check_box_widget);

  check_box_widget->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

  layout->addStretch(0);
}

void histogram_widget::update_charts(histogram hist) {  
  connect(red_chkbox,&QAbstractButton::clicked,&chart_histogram,&chart_representation::toggle_r);
  connect(red_chkbox,&QAbstractButton::clicked,&chart_ac_histogram,&chart_representation::toggle_r);

  connect(green_chkbox,&QAbstractButton::clicked,&chart_histogram,&chart_representation::toggle_g);
  connect(green_chkbox,&QAbstractButton::clicked,&chart_ac_histogram,&chart_representation::toggle_g);

  connect(blue_chkbox,&QAbstractButton::clicked,&chart_histogram,&chart_representation::toggle_b);
  connect(blue_chkbox,&QAbstractButton::clicked,&chart_ac_histogram,&chart_representation::toggle_b);


  chart_histogram.update_values(hist.regular_r, hist.regular_g, hist.regular_b);
  chart_ac_histogram.update_values(hist.acumulated_r, hist.acumulated_g, hist.acumulated_b);
}
