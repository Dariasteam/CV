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
  QLineSeries series;
public:
  chart_representation(QWidget* parent = nullptr);
public slots:
  void update (const std::vector<unsigned>& h);

};

#endif // CHART_REPRESENTATION_H
