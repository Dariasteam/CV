#include "menu.h"

point_representation::point_representation(QPoint point,
                                           bool closable,
                                           QWidget *parent) :
  QWidget (parent)
{
  layout = new QBoxLayout (QBoxLayout::LeftToRight, this);
  x = new QSpinBox (this);
  y = new QSpinBox (this);

  close_bttn = new QPushButton (CLOSE_TXT, this);

  x->setMaximum(255);
  y->setMaximum(255);

  layout->addWidget(x);
  layout->addWidget(y);
  layout->addWidget(close_bttn);

  if (!closable)
    close_bttn->setEnabled(false);

  connect(x,SIGNAL(valueChanged(int)),this,SIGNAL(on_check_value(int)));
  connect(y,SIGNAL(valueChanged(int)),this,SIGNAL(on_check_value(int)));

  on_set_values(point.x(), point.y());
}

void point_representation::on_set_values(unsigned X, unsigned Y) {
  x->setValue(X);
  y->setValue(Y);
}

void point_representation::on_check_value(int) {
  emit check_values(x->value(), y->value());
}

curve_chart::curve_chart(model *mdl) {
  setMouseTracking(true);

  connect(this,SIGNAL(chart_clicked(QPoint,double)),(model*)mdl,
               SLOT(on_click_point(QPoint,double)));

  connect(this,SIGNAL(update_point(QPoint,double)),(model*)mdl,
               SLOT(on_update_point(QPoint,double)));

  connect(this,SIGNAL(release()),mdl,SLOT(on_release_point()));
}

void curve_chart::mouseMoveEvent(QMouseEvent *ev) {  
  double factor = (double(width())/ double(DEPTH));

  SyncPoint p (ev->pos());
  p.setY(double(height()) - double(p.y()));
  p.setX(p.x() / factor);

  emit update_point(p, factor);
}

void curve_chart::mousePressEvent(QMouseEvent *ev) {  
  double factor = (double(width())/ double(DEPTH));
  emit chart_clicked(ev->pos(), factor);
}

void curve_chart::mouseReleaseEvent(QMouseEvent *ev) {
  emit release();
}

menu::menu(model* m, QWidget *parent) :
  view_interface(parent),
  mdl (m),
  chart_view (m)
{    


  connect(m,SIGNAL(update_chart(QList<SyncPoint*>)),this,
            SLOT(on_update_points(QList<SyncPoint*>)));

  layout = new QBoxLayout (QBoxLayout::TopToBottom, this);

  chart_container = new QWidget(this);
  chart_container->setFixedHeight(300);
  chart_container->setLayout(new QBoxLayout (QBoxLayout::TopToBottom, this));

  labels_container = new QWidget(this);
  labels_container->setLayout(new QBoxLayout (QBoxLayout::TopToBottom, this));

  chart_view.setRenderHint(QPainter::Antialiasing);
  chart.legend()->setVisible(false);
  chart_view.setChart(&chart);

  chart_line_serie = new QLineSeries;
  *chart_line_serie << QPoint(0,0) << QPoint(DEPTH - 1, DEPTH - 1);
  chart.addSeries(chart_line_serie);
  chart.setMargins(QMargins(0,0,0,0));

  on_update_points(mdl->points);


  chart_container->layout()->addWidget(&chart_view);

  layout->addWidget(chart_container);
  layout->addWidget(labels_container);
}

void menu::on_update_points(QList<SyncPoint*> points) {

  emit update_lut(points);

  chart_line_serie->clear();    

  QLayoutItem *child;
  while ((child = labels_container->layout()->takeAt(0)) != 0)  {
    child->widget()->deleteLater();
  }

  for (unsigned i = 0; i < points.size(); i++) {
    SyncPoint aux = *(points.at(i));
    *chart_line_serie << aux;
    point_representation* l_aux =new point_representation(aux, this);


    connect(l_aux,SIGNAL(check_values(uint,uint)),
                   &aux,SLOT(on_update_position(uint,uint)));


    labels_container->layout()->addWidget(l_aux);
  }  

}
