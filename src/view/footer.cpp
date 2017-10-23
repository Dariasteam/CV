#include "footer.h"

footer::footer(QWidget *parent) : QStatusBar(parent) {
  x_pixel_label = new QLabel(X_STRING, this);
  y_pixel_label = new QLabel(Y_STRING, this);

  image_format = new QLabel (FORMAT_STRING, this);
  image_size = new QLabel (SIZE_STRING, this);

  rgb_values = new QLabel (R_VALUE G_VALUE B_VALUE, this);

  addWidget(x_pixel_label);
  addWidget(y_pixel_label);
  addWidget(image_format);
  addWidget(image_size);
  addWidget(rgb_values);
}

void footer::on_update_coordenate_labels(QPoint point) {
  x_pixel_label->setText(X_STRING + QString::number(point.x()));
  y_pixel_label->setText(Y_STRING + QString::number(point.y()));
  emit get_rgb_at(point);
}

void footer::on_update_rgb_at(QColor color) {
  rgb_values->setText(R_VALUE + QString::number(color.red  ()) +
                      G_VALUE + QString::number(color.green()) +
                      B_VALUE + QString::number(color.blue ()));
}

void footer::on_update_meta_data(QString format, QSize size) {
  image_format->setText(FORMAT_STRING + format);
  image_size->setText(SIZE_STRING + QString::number(size.width()) +
                      ", " + QString::number(size.height()));
}
