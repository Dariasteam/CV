#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Creación del main widget
  window_content = new view (this);
  setCentralWidget(window_content);
  connect(window_content,SIGNAL(image_focused()),this,SLOT(on_image_focused()));
  connect(window_content,SIGNAL(no_image_focused()),this,SLOT(on_no_focused_image()));

  // Creación de menús
  generate_menu();

  // Creación del dock
  dock = new options_dock (this);
  dock->setFeatures(QDockWidget::DockWidgetMovable);
  addDockWidget(Qt::RightDockWidgetArea, dock);

  // Creación del toolbar
  toolbar = new QToolBar (this);
  addToolBar(Qt::ToolBarArea::TopToolBarArea, toolbar);  

  // Creación del footer
  foot = new footer(this);
  setStatusBar(foot);


}

void MainWindow::generate_menu() {
  menu_bar = new QMenuBar (this);

  for (unsigned i = 0; i < menu_strings[0].size(); i++) {
    QMenu* aux_menu = new QMenu (menu_strings[0][i], menu_bar);
    menu_bar->addMenu(aux_menu);
    for (unsigned j = 0; j < menu_strings[i + 1].size(); j++) {
      QAction* aux_action = new QAction (menu_strings[i + 1][j], aux_menu);
      aux_menu->addAction(aux_action);
    }
  }

  on_no_focused_image();

  menu_bar->actions()[0]->menu()->actions()[0]->setShortcut(QKeySequence("Ctrl+O"));
  menu_bar->actions()[0]->menu()->actions()[1]->setShortcut(QKeySequence("Ctrl+S"));

  connect(menu_bar->actions()[0]->menu()->actions()[0], SIGNAL(triggered(bool)), this, SLOT(on_bttn_load(bool)));
  connect(menu_bar->actions()[0]->menu()->actions()[1], SIGNAL(triggered(bool)), this, SLOT(on_bttn_save(bool)));

  setMenuBar(menu_bar);
}

void MainWindow::on_bttn_load(bool) {
  QString filename = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), ".", tr("Imagen (*.png *.jpg *.tiff)"));
  if (!filename.isEmpty())
    emit load_image(filename);
}

void MainWindow::on_bttn_save(bool) {
  if (window_content->theres_active_window()) {
    QString filename = QFileDialog::getSaveFileName(this, tr("Guardar imagen"), ".", tr("Imagen (*.png *.jpg *.tiff)"));
    emit save_image(filename, window_content->get_active_canvas());
  }
}

void MainWindow::on_image_focused() {
  menu_bar->actions()[0]->menu()->actions()[1]->setEnabled(true);
  menu_bar->actions()[0]->menu()->actions()[2]->setEnabled(true);
}

void MainWindow::on_no_focused_image() {
  menu_bar->actions()[0]->menu()->actions()[1]->setEnabled(false);
  menu_bar->actions()[0]->menu()->actions()[2]->setEnabled(false);
}

MainWindow::~MainWindow()
{
  delete ui;
}
