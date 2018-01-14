#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <sstream>
#include <exception>

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QTextEdit>

#include "../../model/picture.h"

#define INPUT_TXT "Kernel custom"

#define MIN_RANGE 3
#define MAX_RANGE 30
#define DEFAULT_VALUE 3

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class menu : public view_interface {  
  Q_OBJECT
private:
  QTextEdit* user_input;
  QBoxLayout* layout;
public:  
  explicit menu(QWidget *parent = nullptr);
private slots:
  void check_kernel();
signals:
  void kernel_valid (std::vector<std::vector<int>>);

};

#endif // MENU_H

