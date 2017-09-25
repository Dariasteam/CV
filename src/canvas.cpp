#include "canvas.h"

#include <QLabel>
#include <QBoxLayout>

canvas::canvas(QWidget *parent) : QWidget(parent)
{
  QBoxLayout* lay = new QBoxLayout(QBoxLayout::Direction::LeftToRight, this);
  setLayout(lay);

  lay->addWidget(new QLabel("asdasdasd", this));

}
