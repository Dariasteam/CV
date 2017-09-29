#include "options_dock.h"

options_dock::options_dock(QWidget* parent) : QDockWidget(parent) {
  QWidget* base_widget = new QWidget (this);
  setWidget(base_widget);

  QBoxLayout* layout = new QBoxLayout(QBoxLayout::TopToBottom,base_widget);

  base_widget->setLayout(layout);

  QLabel* title_label = new QLabel (tr("Propiedades"), base_widget);
  setTitleBarWidget(title_label);

}
