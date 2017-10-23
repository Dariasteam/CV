#include "options_dock.h"

options_dock::options_dock(QWidget* parent) : QDockWidget(parent) {
  QWidget* base_widget = new QWidget (this);
  setWidget(base_widget);

  setDisabled(true);

  QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom,base_widget);

  base_widget->setLayout(layout);

  QLabel* title_label = new QLabel (tr("Propiedades"), base_widget);
  setTitleBarWidget(title_label);

  histogram_wid = new histogram_widget (base_widget);
  layout->addWidget(histogram_wid);

  image_info_wid = new image_info_widget (base_widget);
  layout->addWidget(image_info_wid);

  operation_wid = new operation_options_widget (base_widget);
  layout->addWidget(operation_wid);
  layout->addStretch(0);
}
