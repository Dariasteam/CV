#include "canvas.h"

canvas::canvas(QWidget *parent) : QLabel(parent, Qt::CustomizeWindowHint) {
  QImage* image = new QImage;
  image->load(QString("1.png"));
  this->setPixmap(QPixmap::fromImage(*image));

}
