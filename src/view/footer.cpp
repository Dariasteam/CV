#include "footer.h"

footer::footer(QWidget *parent) : QStatusBar(parent) {
  x_pixel_label = new QLabel(X_STRING, this);
  y_pixel_label = new QLabel(Y_STRING, this);

  image_format = new QLabel (FORMAT_STRING, this);
  image_size = new QLabel (SIZE_STRING, this);

  addWidget(x_pixel_label);
  addWidget(y_pixel_label);
  addWidget(image_format);
  addWidget(image_size);
}

void footer::on_update_coordinate_labels(QPoint point) {
  x_pixel_label->setText(X_STRING + QString::number(point.x()));
  y_pixel_label->setText(Y_STRING + QString::number(point.y()));
}

void footer::on_update_meta_data(QString format, QSize size) {

}
