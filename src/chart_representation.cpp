#include "chart_representation.h"

chart_representation::chart_representation(QWidget* parent) : QChartView(parent),
  red (Qt::red),
  green (Qt::green),
  blue (Qt::blue)
{

  chart.legend()->setVisible(false);
  chart.setMargins(QMargins(0,0,0,0));  
  chart.setAnimationOptions(QChart::AllAnimations);

  setRenderHint(QPainter::Antialiasing);

  setMaximumHeight(MAX_HEIGHT);


  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

  red.setAlpha(100);
  green.setAlpha(100);
  blue.setAlpha(80);

  setChart(&chart);

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

void chart_representation::update(const std::vector<unsigned> &hr,
                                  const std::vector<unsigned> &hg,
                                  const std::vector<unsigned> &hb) {
  chart.removeSeries(area_series_r);
  chart.removeSeries(area_series_g);
  chart.removeSeries(area_series_b);

  area_series_r = represent(hr);
  area_series_g = represent(hg);
  area_series_b = represent(hb);

  area_series_r->setColor(red);
  area_series_g->setColor(green);
  area_series_b->setColor(blue);

  chart.addSeries(area_series_r);
  chart.addSeries(area_series_g);
  chart.addSeries(area_series_b);
}

