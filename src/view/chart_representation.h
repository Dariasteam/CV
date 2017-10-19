#ifndef CHART_REPRESENTATION_H
#define CHART_REPRESENTATION_H

#include <vector>

#include <QWidget>
#include <QtCharts>
#include <QChart>
#include <QBoxLayout>

#define MIN_HEIGHT 300
#define REGULAR_ALPHA 100

class chart_representation : public QWidget {
private:
  QChartView view;
  QChart chart;  
  QAreaSeries* area_series_r;
  QAreaSeries* area_series_g;
  QAreaSeries* area_series_b;  

  bool usable;
  bool r;
  bool g;
  bool b;

  QColor red;
  QColor green;
  QColor blue;

  QAreaSeries* represent (const std::vector<unsigned>& h);
public:
  chart_representation(QWidget* parent = nullptr);
public slots:
  void update_values (const std::vector<unsigned>& hr,
                      const std::vector<unsigned>& hg,
                      const std::vector<unsigned>& hb);

  void toggle_r (bool r);
  void toggle_g (bool g);
  void toggle_b (bool b);

  void update_view ();

  inline void set_usable (bool b) { usable = b; }
};

#endif // CHART_REPRESENTATION_H
