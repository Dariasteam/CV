#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>

#define INFO_TXT "Pulse aplicar para establecer la transformación "

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class menu : public view_interface {
  Q_OBJECT
private:
  QLabel* info;
public:
  explicit menu(QWidget *parent = nullptr);
};

#endif // MENU_H

