#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>

#define INFO_TXT "Selecciona un área de la imagen y " \
                 "pulsa aplicar para recortarla"

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

