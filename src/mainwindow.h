#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QString>

#include <vector>

#include "view.h"

using namespace std;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

private:

  vector <vector <QString>> menu_strings = { {"Archivo", "Editar", "Acerca de"},
                                             {"a_op_1",  "e_op_1"},
                                             {"a_op_2",  "e_op_2"},
                                             {"a_op_3"}
                                                                              };


  view* window_content;
  QMenuBar* menu_bar;
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
