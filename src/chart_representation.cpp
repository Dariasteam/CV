#include "chart_representation.h"

chart_representation::chart_representation(QWidget* parent) : QChartView(parent)
{

  chart.legend()->setVisible(false);
  chart.setMargins(QMargins(0,0,0,0));
  chart.addSeries(&series);
  chart.setAnimationOptions(QChart::AllAnimations);

  setRenderHint(QPainter::Antialiasing);

  setMaximumHeight(MAX_HEIGHT);

  setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
  setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);



  setChart(&chart);
}

void chart_representation::update(const std::vector<unsigned> &h) {  
  series.clear();
  for (unsigned i = 0; i < h.size(); i++) {
    series << QPoint(i, h[i]);
  }

  chart.removeSeries(&series);
  chart.addSeries(&series);
}
