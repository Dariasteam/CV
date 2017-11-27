#ifndef MENU_H
#define MENU_H

#include <iostream>

#include <QWidget>
#include <QSlider>
#include <QBoxLayout>
#include <QLabel>
#include <QCheckBox>

#include "../../model/picture.h"

#define GAMMA_TXT "Gamma"

#define MIN_RANGE 0
#define MAX_RANGE 600
#define DEFAULT_VALUE 600
#define DIVISOR 5

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class gamma_slider : public QWidget {
  Q_OBJECT
private:
  QBoxLayout* layout;
  QLabel* value_indicator;
  QSlider* slider;
public:
  explicit gamma_slider () {
    layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    value_indicator = new QLabel (this);
    value_indicator->setMinimumWidth(20);
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(MIN_RANGE, MAX_RANGE);
    slider->setValue(DEFAULT_VALUE / DIVISOR);

    layout->addWidget(slider);
    layout->addWidget(value_indicator);

    connect(slider,SIGNAL(sliderMoved(int)),this,SLOT(on_slider_moved(int)));
  }
  inline QSlider* get_slider () { return slider; }
private slots:
  void on_slider_moved (int i) {
    value_indicator->setText(QString::number(double(i) / double(DEFAULT_VALUE / DIVISOR)));
  }
};

class menu : public view_interface {  
  Q_OBJECT
private:
  QBoxLayout* layout;
public:
  gamma_slider* gamma_s;
  explicit menu(QWidget *parent = nullptr);
};

#endif // MENU_H

