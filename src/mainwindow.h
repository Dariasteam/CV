#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QList>
#include <QString>
#include <QToolBar>
#include <QFileDialog>
#include <QPoint>
#include <QKeySequence>

#include <vector>

#include "view.h"

using namespace std;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

private:

  vector <vector <QString>> menu_strings =  { {"Archivo", "Editar", "Acerca de"},
                                              {"Abrir", "Guardar", "Guardar como" },
                                              {},
                                              {}
                                            };


  view* window_content;
  QMenuBar* menu_bar;
  options_dock* dock;
  QToolBar* toolbar;  
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  inline view* get_view () { return window_content; }

private:
  Ui::MainWindow *ui;
  void generate_menu();

private slots:
  void on_bttn_load (bool);
  void on_bttn_save (bool);
  void on_image_focused();
  void on_no_focused_image ();
signals:
  void load_image(QString file_name);
  void save_image(QString file_name, unsigned i);

};

#endif // MAINWINDOW_H
