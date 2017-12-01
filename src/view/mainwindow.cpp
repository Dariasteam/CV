#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
//  ui->setupUi(this);

  // Creación del footer
  foot = new footer(this);
  setStatusBar(foot);

  // Creación del main widget
  window_content = new view (foot, this);
  setCentralWidget(window_content);
  connect(window_content,&view::image_focused,this,&MainWindow::on_image_focused);
  connect(window_content,&view::no_image_focused,this,&MainWindow::on_no_focused_image);

  // Creación de menús
  generate_menu();

  // Creación del dock
  op_dock = new options_dock (this);
  op_dock->setFeatures(QDockWidget::DockWidgetMovable);
  addDockWidget(Qt::RightDockWidgetArea, op_dock);
/*
  // Creación del toolbar
  toolbar = new QToolBar (this);
  addToolBar(Qt::ToolBarArea::TopToolBarArea, toolbar);
*/
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

  load = menu_bar->actions()[0]->menu()->actions()[0];
  save = menu_bar->actions()[0]->menu()->actions()[1];
  save_as = menu_bar->actions()[0]->menu()->actions()[2];

  load->setShortcut(QKeySequence("Ctrl+O"));
  save->setShortcut(QKeySequence("Ctrl+S"));

  save_as->setEnabled(false);
  save->setEnabled(false);

  connect(load, &QAction::triggered, this, &MainWindow::on_bttn_load);
  connect(save, &QAction::triggered, this, &MainWindow::on_bttn_save);

  plugin_menu = menu_bar->findChildren<QMenu*>().at(3);

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
    emit save_image(filename, window_content->get_active_picture_id());
  }
}

void MainWindow::on_image_focused() {
  save->setEnabled(true);
  save_as->setEnabled(true);

  plugin_menu->setEnabled(true);
  op_dock->setEnabled(true);
}

void MainWindow::on_no_focused_image() {
  save->setEnabled(false);
  save_as->setEnabled(false);

  plugin_menu->setEnabled(false);
  op_dock->setEnabled(false);
  op_dock->get_histogram_wid()->on_clear_charts();
}

indexed_action* MainWindow::on_add_plugin(QString category, QString name, unsigned i) {
  int index = 0;
  for (auto c_name : menu_strings[0]) {
    if (c_name == category)
      break;    
    index++;
  } 

  QMenu* menu;

  if (index >= menu_strings[0].size()) {
    menu_strings[0].push_back(category);
    menu = menu_bar->addMenu(category);
  } else {
    menu = menu_bar->findChildren<QMenu*>().at(index + 1);
  }

  indexed_action* action = new indexed_action (name, i, menu);

  menu->addAction(action);
  return action;
}

MainWindow::~MainWindow()
{
  delete ui;
}
