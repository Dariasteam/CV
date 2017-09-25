#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  window_content = new view (this);
  setCentralWidget(window_content);

  // Creación de menús

  menu_bar = new QMenuBar (this);

  for (unsigned i = 0; i < menu_strings[0].size(); i++) {
    QMenu* aux_menu = new QMenu (menu_strings[0][i], menu_bar);
    menu_bar->addMenu(aux_menu);
    for (unsigned j = 0; j < menu_strings[i + 1].size(); j++) {
      QAction* aux_action = new QAction (menu_strings[i + 1][j], aux_menu);
      aux_menu->addAction(aux_action);
    }
  }

  setMenuBar(menu_bar);

}

MainWindow::~MainWindow()
{
  delete ui;
}
