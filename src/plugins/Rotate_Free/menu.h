#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QSlider>

#define INFO_TXT "Pulse aplicar para establecer la transformación "

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class menu : public view_interface {
  Q_OBJECT
private:
  QSpinBox* spin_rotate;
  QSlider* slider_rotate;
public:
  explicit menu(QWidget *parent = nullptr);
  QSlider* get_slider_rotate () { return slider_rotate; }
signals:  
};

#endif // MENU_H

