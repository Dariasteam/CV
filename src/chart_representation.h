#ifndef CHART_REPRESENTATION_H
#define CHART_REPRESENTATION_H

#include <vector>

#include <QWidget>
#include <QtCharts>
#include <QChart>

#define MAX_WIDTH 300
#define MAX_HEIGHT 300

class chart_representation : public QChartView {
private:
  QChart chart;  
  QAreaSeries* area_series_r;
  QAreaSeries* area_series_g;
  QAreaSeries* area_series_b;

  QColor red;
  QColor green;
  QColor blue;

  QAreaSeries* represent (const std::vector<unsigned>& h);
public:
  chart_representation(QWidget* parent = nullptr);
public slots:
  void update (const std::vector<unsigned>& hr,
               const std::vector<unsigned>& hg,
               const std::vector<unsigned>& hb);

};

#endif // CHART_REPRESENTATION_H
