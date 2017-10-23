#include "image_info_widget.h"

image_info_widget::image_info_widget(QWidget *parent) : QWidget(parent)
{      

  layout = new QGridLayout(this);  
  setLayout(layout);

  layout->addWidget(new QLabel ("R", this), 0, 1);
  layout->addWidget(new QLabel ("G", this), 0, 2);
  layout->addWidget(new QLabel ("B", this), 0, 3);

  layout->addWidget(new QLabel ("Brillo", this), 1, 0);

  brightness = {new QLabel(this), new QLabel(this), new QLabel(this)};

  layout->addWidget(brightness.r, 1, 1);
  layout->addWidget(brightness.g, 1, 2);
  layout->addWidget(brightness.b, 1, 3);

  layout->addWidget(new QLabel ("Contraste", this), 2, 0);

  contrast = {new QLabel(this), new QLabel(this), new QLabel(this)};

  layout->addWidget(contrast.r, 2, 1);
  layout->addWidget(contrast.g, 2, 2);
  layout->addWidget(contrast.b, 2, 3);

  layout->addWidget(new QLabel ("Rango", this), 3, 0);

  range = {new QLabel(this), new QLabel(this), new QLabel(this)};

  layout->addWidget(range.r, 3, 1);
  layout->addWidget(range.g, 3, 2);
  layout->addWidget(range.b, 3, 3);

  layout->addWidget(new QLabel ("Rango dinámico", this), 4, 0);

  dynamic_range = new QLabel(this);
  layout->addWidget(dynamic_range, 4, 1, 0, 0);

  layout->addWidget(new QLabel ("Entropía", this), 5, 0);

  //entropy = new QLabel(this);
//layout->addWidget(entropy, 3, 1, 0, 0);

}

void image_info_widget::on_update_basic_info(const picture_basic_info &info) {
  brightness.r->setText(QString::number(info.average.r));
  brightness.g->setText(QString::number(info.average.g));
  brightness.b->setText(QString::number(info.average.b));

  contrast.r->setText(QString::number(info.deviation.r));
  contrast.g->setText(QString::number(info.deviation.g));
  contrast.b->setText(QString::number(info.deviation.b));
/*
  range.r->setText(QString::number(info.range.r));
  range.g->setText(QString::number(info.range.g));
  range.b->setText(QString::number(info.range.b));
*/
  /*
  dynamic_range->setText(QString::number(info.dynamic_range));
*//*
  entropy->setText(QString::number(info.entropy));
  */
}

void image_info_widget::on_clear_basic_info() {

}
