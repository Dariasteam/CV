#include "image_info_widget.h"

image_info_widget::image_info_widget(QWidget *parent) : QWidget(parent)
{
  brightness    = {new QLabel(this), new QLabel(this), new QLabel(this)};
  contrast      = {new QLabel(this), new QLabel(this), new QLabel(this)};
  entropy       = {new QLabel(this), new QLabel(this), new QLabel(this)};
  range_min     = {new QLabel(this), new QLabel(this), new QLabel(this)};
  range_max     = {new QLabel(this), new QLabel(this), new QLabel(this)};
  dynamic_range = {new QLabel(this), new QLabel(this), new QLabel(this)};

  //  HEADER
  layout = new QGridLayout(this);  
  setLayout(layout);
  layout->addWidget(new QLabel ("R", this), 0, 1);
  layout->addWidget(new QLabel ("G", this), 0, 3);
  layout->addWidget(new QLabel ("B", this), 0, 5);

  // BRIGHTNESS
  layout->addWidget(new QLabel ("Brillo", this), 1, 0);
  layout->addWidget(brightness.r, 1, 1);
  layout->addWidget(brightness.g, 1, 3);
  layout->addWidget(brightness.b, 1, 5);

  // CONTRAST
  layout->addWidget(new QLabel ("Contraste", this), 2, 0);
  layout->addWidget(contrast.r, 2, 1);
  layout->addWidget(contrast.g, 2, 3);
  layout->addWidget(contrast.b, 2, 5);

  // DYNAMIC RANGE
  layout->addWidget(new QLabel ("Rango dinámico", this), 3, 0);
  layout->addWidget(dynamic_range.r, 3, 1);
  layout->addWidget(dynamic_range.g, 3, 3);
  layout->addWidget(dynamic_range.b, 3, 5);

  // ENTROPY
  layout->addWidget(new QLabel ("Entropía", this), 4, 0);
  layout->addWidget(entropy.r, 4, 1);
  layout->addWidget(entropy.g, 4, 3);
  layout->addWidget(entropy.b, 4, 5);

  // RANGE
  layout->addWidget(new QLabel ("Rango", this), 5, 0);
  layout->addWidget(range_min.r, 5, 1);
  layout->addWidget(range_min.g, 5, 3);
  layout->addWidget(range_min.b, 5, 5);

  layout->addWidget(range_max.r, 5, 2);
  layout->addWidget(range_max.g, 5, 4);
  layout->addWidget(range_max.b, 5, 6);

  // MIN MAX
  layout->addWidget(new QLabel ("min", this), 6, 1);
  layout->addWidget(new QLabel ("max", this), 6, 2);
  layout->addWidget(new QLabel ("min", this), 6, 3);

  layout->addWidget(new QLabel ("max", this), 6, 4);
  layout->addWidget(new QLabel ("min", this), 6, 5);
  layout->addWidget(new QLabel ("max", this), 6, 6);
}

void image_info_widget::on_update_basic_info(const picture_basic_info &info) {
  // BRILLO
  brightness.r->setText(QString::number(info.average.r));
  brightness.g->setText(QString::number(info.average.g));
  brightness.b->setText(QString::number(info.average.b));

  // CONTRASTE
  contrast.r->setText(QString::number(info.deviation.r));
  contrast.g->setText(QString::number(info.deviation.g));
  contrast.b->setText(QString::number(info.deviation.b));

  // RANGO
  range_min.r->setText(QString::number(info.range.r.first));
  range_min.g->setText(QString::number(info.range.g.first));
  range_min.b->setText(QString::number(info.range.b.first));

  range_max.r->setText(QString::number(info.range.r.second));
  range_max.g->setText(QString::number(info.range.g.second));
  range_max.b->setText(QString::number(info.range.b.second));

  // RANGO DINÄMICO
  dynamic_range.r->setText(QString::number(info.dynamic_range.r));
  dynamic_range.g->setText(QString::number(info.dynamic_range.g));
  dynamic_range.b->setText(QString::number(info.dynamic_range.b));

  // ENTOPÍA
  entropy.r->setText(QString::number(info.entropy.r));
  entropy.g->setText(QString::number(info.entropy.g));
  entropy.b->setText(QString::number(info.entropy.b));
}

void image_info_widget::on_clear_basic_info() {
  // BRILLO
  brightness.r->clear();
  brightness.g->clear();
  brightness.b->clear();

  // CONTRASTE
  contrast.r->clear();
  contrast.g->clear();
  contrast.b->clear();

  // RANGO
  range_min.r->clear();
  range_min.g->clear();
  range_min.b->clear();

  range_max.r->clear();
  range_max.g->clear();
  range_max.b->clear();

  // RANGO DINÄMICO
  dynamic_range.r->clear();
  dynamic_range.g->clear();
  dynamic_range.b->clear();

  // ENTOPÍA
  entropy.r->clear();
  entropy.g->clear();
  entropy.b->clear();
}
