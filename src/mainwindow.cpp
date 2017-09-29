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
  generate_menu();

  // Creación del dock
  dock = new options_dock (this);
  dock->setFeatures(QDockWidget::DockWidgetMovable);
  addDockWidget(Qt::RightDockWidgetArea, dock);

  // Creación del toolbar
  toolbar = new QToolBar (this);
  addToolBar(Qt::ToolBarArea::TopToolBarArea, toolbar);  
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

  connect(menu_bar->actions()[0]->menu()->actions()[0], SIGNAL(triggered(bool)), this, SLOT(on_bttn_load(bool)));
  connect(menu_bar->actions()[0]->menu()->actions()[1], SIGNAL(triggered(bool)), this, SLOT(on_bttn_save(bool)));

  setMenuBar(menu_bar);
}


void MainWindow::on_bttn_load(bool) {
  QString filename = QFileDialog::getOpenFileName(this, tr("Abrir imagen"), ".", tr("Imagen (*.png *.jpg *.tiff)"));
  emit load_image(filename);
}

void MainWindow::on_bttn_save(bool) {
  QString filename = QFileDialog::getSaveFileName(this, tr("Guardar imagen"), ".", tr("Imagen (*.png *.jpg *.tiff)"));
  emit save_image(filename);
}

MainWindow::~MainWindow()
{
  delete ui;
}
