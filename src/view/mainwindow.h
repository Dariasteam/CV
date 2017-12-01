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
#include "footer.h"
#include "options_dock.h"
#include "../controller/indexed_action.h"

using namespace std;

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

private:

  vector <vector <QString>> menu_strings =  { {"Archivo", "Editar", "Filtro", "Operaciones lineales", "Operaciones no lineales", "Acerca de"},
                                              {"Abrir", "Guardar", "Guardar como" },
                                              {},
                                              {},
                                              {},                                              
                                              {}
                                            };


  view* window_content;
  QMenuBar* menu_bar;
  options_dock* op_dock;
  QToolBar* toolbar;
  footer* foot;  
  QMenu* plugin_menu;

  QAction* load;
  QAction* save;
  QAction* save_as;
public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  inline view* get_view () { return window_content; }
  inline options_dock* get_options_dock () { return op_dock; }  
  inline footer* get_footer () { return foot; }
private:
  Ui::MainWindow *ui;
  void generate_menu();
private slots:  
  void on_bttn_load (bool);
  void on_bttn_save (bool);
  void on_image_focused();
  void on_no_focused_image ();
public slots:
  indexed_action* on_add_plugin (QString category, QString name, unsigned index);
signals:
  void load_image(QString file_name);
  void save_image(QString file_name, unsigned i);
};

#endif // MAINWINDOW_H
