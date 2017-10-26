#ifndef MENU_H
#define MENU_H

#include <iostream>

#include <QWidget>
#include <QSlider>
#include <QBoxLayout>
#include <QLabel>
#include <QCheckBox>

#define BRIGHTNESS_TXT "Brillo"
#define CONTRAST_TXT    "Contraste"

#define R_TEXT "R"
#define G_TEXT "G"
#define B_TEXT "B"

#define FIXED_TEXT "Bloquear canales"

#define MIN_RANGE_B 1
#define MAX_RANGE_B 1000
#define DEFAULT_B 0

#define MIN_RANGE_C 1
#define MAX_RANGE_C 30
#define DEFAULT_C 10

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class b_c_slider : public QWidget {
  Q_OBJECT
private:
  QBoxLayout* layout;
  QLabel* value_indicator;
  QSlider* slider;
public:
  explicit b_c_slider (const QString& channel_name, int a, int b, int c) {
    layout = new QBoxLayout(QBoxLayout::LeftToRight, this);
    value_indicator = new QLabel (this);
    value_indicator->setMinimumWidth(20);
    slider = new QSlider(Qt::Horizontal, this);
    slider->setRange(a,b);
    slider->setValue(c);

    layout->addWidget(new QLabel (channel_name, this));
    layout->addWidget(slider);
    layout->addWidget(value_indicator);

    connect(slider,SIGNAL(valueChanged(int)),this,SLOT(on_slider_moved(int)));
  }
  inline QSlider* get_slider () { return slider; }
private slots:
  void on_slider_moved (int i) {
    value_indicator->setText(QString::number(i));
  }
};

class slider_group : public QWidget {
  Q_OBJECT
private:
  b_c_slider* r;
  b_c_slider* g;
  b_c_slider* b;

  QBoxLayout* layout;
  bool fixed;

public:
  explicit slider_group (const QString& name_1,
                         const QString& name_2,
                         const QString& name_3,
                         int a, int z, int c) {

    r = new b_c_slider(name_1, a, z, c);
    g = new b_c_slider(name_2, a, z, c);
    b = new b_c_slider(name_3, a, z, c);

    layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
    setLayout(layout);

    connect(r->get_slider(),SIGNAL(sliderMoved(int)),
            this, SLOT(on_propagate_values(int)));
    connect(g->get_slider(),SIGNAL(sliderMoved(int)),
            this, SLOT(on_propagate_values(int)));
    connect(b->get_slider(),SIGNAL(sliderMoved(int)),
            this, SLOT(on_propagate_values(int)));

    connect(r->get_slider(),SIGNAL(valueChanged(int)),
            this, SLOT(on_replicate_values(int)));
    connect(g->get_slider(),SIGNAL(valueChanged(int)),
            this, SLOT(on_replicate_values(int)));
    connect(b->get_slider(),SIGNAL(valueChanged(int)),
            this, SLOT(on_replicate_values(int)));

    layout->addWidget(r);
    layout->addWidget(g);
    layout->addWidget(b);
  }  

  void set_fixed (bool f) {
    fixed = f;
  }
private slots:
  void on_replicate_values (int v) {
    if (fixed) {
      r->get_slider()->setValue(v);
      g->get_slider()->setValue(v);
      b->get_slider()->setValue(v);
    }
  }

  void on_propagate_values (int v) {
    update_values (
      r->get_slider()->value(),
      g->get_slider()->value(),
      b->get_slider()->value()
    );
  }
signals:
  void update_values (int, int, int);
};

class menu : public view_interface {  
  Q_OBJECT
private:
  QBoxLayout* layout;
  slider_group* brightness_sliders;
  slider_group* contrast_sliders;
  QCheckBox* fixed_checkbox;
public:
  explicit menu(QWidget *parent = nullptr);  
  inline slider_group* get_bright_values ()   { return brightness_sliders;}
  inline slider_group* get_contrast_values () { return contrast_sliders;} 
  QCheckBox* get_fixed_checkbox () { return fixed_checkbox; }
private slots:
  void on_set_fixed (bool f) {
    brightness_sliders->set_fixed(f);
    contrast_sliders->set_fixed(f);
  }
};

#endif // MENU_H

