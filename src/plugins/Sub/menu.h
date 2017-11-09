#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QPushButton>

#define REQUEST_TXT "Cargar imagen"

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class menu : public view_interface {
  Q_OBJECT  
public:
  QPushButton* request_picture_bttn;
  explicit menu(QWidget *parent = nullptr);
};

#endif // MENU_H

