#include "histogram_widget.h"

histogram_widget::histogram_widget(QWidget *parent) :
  QWidget(parent)
{
  tabs = new QTabWidget (this);
  layout = new QBoxLayout (QBoxLayout::TopToBottom, this);
  tabs->addTab(&chart_histogram, TAB1_NAME);
  tabs->addTab(&chart_ac_histogram, TAB2_NAME);
  layout->addWidget(tabs);

  QWidget* check_box_wiget = new QWidget(this);
  QBoxLayout* check_box_layout = new QBoxLayout(QBoxLayout::LeftToRight);

  red_chkbox   = new QCheckBox (R_CHK_NAME, check_box_wiget);
  green_chkbox = new QCheckBox (G_CHK_NAME, check_box_wiget);
  blue_chkbox  = new QCheckBox (B_CHK_NAME, check_box_wiget);

  red_chkbox->setChecked(true);
  green_chkbox->setChecked(true);
  blue_chkbox->setChecked(true);

  check_box_layout->addWidget(red_chkbox);
  check_box_layout->addWidget(green_chkbox);
  check_box_layout->addWidget(blue_chkbox);

  check_box_wiget->setLayout(check_box_layout);

  layout->addWidget(check_box_wiget);

  connect(red_chkbox,&QAbstractButton::clicked,&chart_histogram,&chart_representation::toggle_r);
  connect(red_chkbox,&QAbstractButton::clicked,&chart_ac_histogram,&chart_representation::toggle_r);

  connect(green_chkbox,&QAbstractButton::clicked,&chart_histogram,&chart_representation::toggle_g);
  connect(green_chkbox,&QAbstractButton::clicked,&chart_ac_histogram,&chart_representation::toggle_g);

  connect(blue_chkbox,&QAbstractButton::clicked,&chart_histogram,&chart_representation::toggle_b);
  connect(blue_chkbox,&QAbstractButton::clicked,&chart_ac_histogram,&chart_representation::toggle_b);


}

void histogram_widget::update_charts(histogram hist) {  
  chart_histogram.update_values(hist.regular_r, hist.regular_g, hist.regular_b);
  chart_ac_histogram.update_values(hist.acumulated_r, hist.acumulated_g, hist.acumulated_b);
}
