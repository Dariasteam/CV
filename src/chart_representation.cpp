#include "chart_representation.h"

chart_representation::chart_representation(QWidget* parent) : QWidget(parent),
  red (Qt::red),
  green (Qt::green),
  blue (Qt::blue),
  r (true),
  g (true),
  b (true),
  view (this)
{


  chart.legend()->setVisible(false);
  //chart.setMargins(QMargins(0,0,0,0));
  chart.setAnimationOptions(QChart::GridAxisAnimations);

  setMinimumHeight(MIN_HEIGHT);
  setMinimumWidth (MIN_HEIGHT);

  red.setAlpha(REGULAR_ALPHA);
  green.setAlpha(REGULAR_ALPHA);
  blue.setAlpha(REGULAR_ALPHA);

  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

  view.setRenderHint(QPainter::Antialiasing);
  view.setChart(&chart);

  QBoxLayout* layout = new QBoxLayout (QBoxLayout::TopToBottom, this);
  setLayout(layout);
  layout->addWidget(&view);
}

QAreaSeries* chart_representation::represent (const std::vector<unsigned>& h) {
  QLineSeries* serie1 = new QLineSeries;
  QLineSeries* serie2 = new QLineSeries;

  for (unsigned i = 0; i < h.size(); i++) {
    *serie1 << QPoint(i, h[i]);
  }
  *serie2 << QPoint(0,1) << QPoint(255,1);

  return new QAreaSeries(serie1, serie2);
}

void chart_representation::toggle_r (bool r){
  red.setAlpha( r ? REGULAR_ALPHA + 50 : 0);
  update_view();
}

void chart_representation::toggle_g (bool g){
  green.setAlpha( g ? REGULAR_ALPHA : 0);
  update_view();
}

void chart_representation::toggle_b (bool b){
  blue.setAlpha( b ? REGULAR_ALPHA : 0);
  update_view();
}

void chart_representation::update_values(const std::vector<unsigned> &hr,
                                         const std::vector<unsigned> &hg,
                                         const std::vector<unsigned> &hb) {
  chart.removeSeries(area_series_r);
  chart.removeSeries(area_series_g);
  chart.removeSeries(area_series_b);

  area_series_r = represent(hr);
  area_series_g = represent(hg);
  area_series_b = represent(hb);

  update_view();
}

void chart_representation::update_view () {
  chart.removeSeries(area_series_r);
  chart.removeSeries(area_series_g);
  chart.removeSeries(area_series_b);

  area_series_r->setColor(red);
  area_series_r->setBorderColor(red);

  area_series_g->setColor(green);
  area_series_g->setBorderColor(green);

  area_series_b->setColor(blue);
  area_series_b->setBorderColor(blue);

  chart.addSeries(area_series_r);  
  chart.addSeries(area_series_g);  
  chart.addSeries(area_series_b);
}

