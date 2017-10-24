#include "footer.h"

footer::footer(QWidget *parent) : QStatusBar(parent) {
  x_pixel_label = new QLabel(X_STRING, this);
  x_pixel_label->setFixedWidth(50);

  y_pixel_label = new QLabel(Y_STRING, this);
  y_pixel_label->setFixedWidth(50);

  image_format = new QLabel (FORMAT_STRING, this);
  image_format->setFixedWidth(100);

  image_size = new QLabel (SIZE_STRING, this);
  image_size->setFixedWidth(120);

  rgb_values = new QLabel (R_VALUE G_VALUE B_VALUE, this);
  rgb_values->setFixedWidth(150);


  rgb_show = new QLabel (this);
  rgb_show->setMinimumWidth(50);
  rgb_show->setAutoFillBackground(true);

  addWidget(x_pixel_label);
  addWidget(y_pixel_label);
  addWidget(image_format);
  addWidget(image_size);
  addWidget(rgb_values);
  addWidget(rgb_show);
}

void footer::on_update_coordenate_labels(QPoint point) {
  x_pixel_label->setText(X_STRING + QString::number(point.x()));
  y_pixel_label->setText(Y_STRING + QString::number(point.y()));
  emit get_rgb_at(point);
}

void footer::on_update_rgb_at(QColor color) {
  QString r = QString::number(color.red  ());
  QString g = QString::number(color.green());
  QString b = QString::number(color.blue ());

  rgb_values->setText(R_VALUE + r +
                      G_VALUE + g +
                      B_VALUE + b);

  QPalette pal (rgb_show->palette());
  pal.setColor(QPalette::Background, color);
  rgb_show->setPalette(pal);
}

void footer::on_update_meta_data(QString format, QSize size) {
  image_format->setText(FORMAT_STRING + format);
  image_size->setText(SIZE_STRING + QString::number(size.width()) +
                      ", " + QString::number(size.height()));
}
