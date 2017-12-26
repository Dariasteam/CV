#include "menu.h"

menu::menu(QWidget *parent) : view_interface(parent)
{

  QGridLayout* layout = new QGridLayout(this);
  setLayout(layout);

  spin_width = new QSpinBox(this);
  spin_height = new QSpinBox(this);

  spin_height->setMaximum(1000);
  spin_width->setMaximum(1000);

  spin_height->setValue(100);
  spin_width->setValue(100);

  spin_height->setMinimum(1);
  spin_width->setMinimum(1);

  spin_height->setSingleStep(1);
  spin_width->setSingleStep(1);

  layout->addWidget(new QLabel("Ancho", this), 0, 0);
  layout->addWidget(spin_width, 0, 1);
  layout->addWidget(new QLabel("Alto", this), 0, 2);
  layout->addWidget(spin_height, 0, 3);

  check_fixed_ratio = new QCheckBox(this);
  check_fixed_ratio->setText("Bloquear ratio");
  layout->addWidget(check_fixed_ratio, 2, 0);

  check_bilinear_filter = new QCheckBox(this);
  check_bilinear_filter->setText("Utilizar filtro bilineal");
  layout->addWidget(check_bilinear_filter, 2, 1, -1, -1);
  check_bilinear_filter->setChecked(true);

  connect(check_fixed_ratio,SIGNAL(toggled(bool)),this,SLOT(on_check_fixed_ration_changed(bool)));
  check_fixed_ratio->setChecked(true);
}

void menu::on_check_fixed_ration_changed(bool b) {
  if (b) {
    connect(spin_height,SIGNAL(valueChanged(int)),this,SLOT(on_height_updated(int)));
    connect(spin_width,SIGNAL(valueChanged(int)),this,SLOT(on_width_updated(int)));

    disconnect(spin_height,SIGNAL(valueChanged(int)),this,SLOT(on_single_update(int)));
    disconnect(spin_width,SIGNAL(valueChanged(int)),this,SLOT(on_single_update(int)));
  } else {
    disconnect(spin_height,SIGNAL(valueChanged(int)),this,SLOT(on_height_updated(int)));
    disconnect(spin_width,SIGNAL(valueChanged(int)),this,SLOT(on_width_updated(int)));

    connect(spin_height,SIGNAL(valueChanged(int)),this,SLOT(on_single_update(int)));
    connect(spin_width,SIGNAL(valueChanged(int)),this,SLOT(on_single_update(int)));
  }
}

void menu::on_single_update(int) {
  emit updated_values(spin_width->value(), spin_height->value());
}

void menu::on_height_updated(int i) {
  disconnect(spin_width,SIGNAL(valueChanged(int)),this,SLOT(on_width_updated(int)));
  spin_width->setValue(i);
  connect(spin_width,SIGNAL(valueChanged(int)),this,SLOT(on_width_updated(int)));
  emit updated_values(i, i);
}

void menu::on_width_updated(int i) {
  disconnect(spin_height,SIGNAL(valueChanged(int)),this,SLOT(on_height_updated(int)));
  spin_height->setValue(i);
  connect(spin_height,SIGNAL(valueChanged(int)),this,SLOT(on_height_updated(int)));
  emit updated_values(i, i);
}

