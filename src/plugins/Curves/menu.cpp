#include "menu.h"

point_representation::point_representation(unsigned X, unsigned Y,
                                           QWidget *parent) :
  QWidget (parent)
{
  layout = new QBoxLayout (QBoxLayout::LeftToRight, this);
  x = new QSpinBox (this);
  y = new QSpinBox (this);

  close_bttn = new QPushButton (CLOSE_TXT, this);

  layout->addWidget(x);
  layout->addWidget(y);
  layout->addWidget(close_bttn);
}

void point_representation::on_set_values(unsigned x, unsigned y) {

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

  QPoint p (ev->pos());
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

  connect(m,SIGNAL(update_chart(QList<QPoint*>)),this,
            SLOT(on_update_points(QList<QPoint*>)));

  layout = new QBoxLayout (QBoxLayout::TopToBottom, this);

  QSizePolicy szp;
  szp.setHorizontalPolicy(QSizePolicy::MinimumExpanding);
  szp.setWidthForHeight(true);
  chart_view.setSizePolicy(szp);  
  chart_view.sizePolicy().setHeightForWidth(true);
  chart_view.size().setHeight(chart_view.size().width());

  chart_view.setRenderHint(QPainter::Antialiasing);
  chart.legend()->setVisible(false);
  chart_view.setChart(&chart);

  chart.setMargins(QMargins(0,0,0,0));

  chart_line_serie = new QLineSeries;

  *chart_line_serie << QPoint(0,0) << QPoint(DEPTH - 1, DEPTH - 1);

  chart.addSeries(chart_line_serie);
  layout->addWidget(&chart_view);
}

void menu::on_update_points(QList<QPoint*> points) {
  chart_line_serie->clear();
  for (unsigned i = 0; i < points.size(); i++) {    
    *chart_line_serie << (*points.at(i));
  }
}
