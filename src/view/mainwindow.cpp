#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow)
{
  ui->setupUi(this);

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

  QAction* load = menu_bar->actions()[0]->menu()->actions()[0];
  QAction* save = menu_bar->actions()[0]->menu()->actions()[1];
  QAction* save_as = menu_bar->actions()[0]->menu()->actions()[2];

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

  op_dock->get_histogram_wid()->on_clear_charts();
}

indexed_action* MainWindow::on_add_plugin(QString category, QString name, unsigned i) {
  int index = -1;
  for (auto m : plugin_menu->findChildren<QMenu*>()) {
    index++;
    if (m->title() == category)
      break;
  }

  QMenu* menu;

  if (index == -1) {
    menu = plugin_menu->addMenu(category);
  } else {
    menu = plugin_menu->findChildren<QMenu*>().at(index);
  }

  indexed_action* action = new indexed_action (name, i, menu);

  menu->addAction(action);
  return action;
}

MainWindow::~MainWindow()
{
  delete ui;
}
