#ifndef HISTOGRAM_WIDGET_H
#define HISTOGRAM_WIDGET_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QChart>
#include <QtCharts>

#include "chart_representation.h"
#include "histogram.h"

#define TAB1_NAME "Histograma"
#define TAB2_NAME "Histograma acumulado"
#define TAB3_NAME "Histograma normalizado"
#define TAB4_NAME "Histograma acumulado normalizado"

class histogram_widget : public QTabWidget
{
  Q_OBJECT
private:
  chart_representation chart_histogram;
  chart_representation chart_ac_histogram;
  chart_representation chart_norm_histogram;
  chart_representation chart_norm_ac_histogram;
public:
  explicit histogram_widget(QWidget *parent = nullptr);

  const chart_representation& get_histogram () { return chart_histogram; }
  const chart_representation& get_ac_histogram () { return chart_ac_histogram; }
  const chart_representation& get_norm_histogram () { return chart_norm_histogram; }
  const chart_representation& get_norm_ac_histogram () { return chart_norm_ac_histogram; }

signals:

public slots:
  void update_charts (histogram hist);
};

#endif // HISTOGRAM_WIDGET_H
