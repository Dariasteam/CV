#ifndef HISTOGRAM_WIDGET_H
#define HISTOGRAM_WIDGET_H

#include <QObject>
#include <QWidget>
#include <QTabWidget>
#include <QChart>
#include <QtCharts>
#include <QBoxLayout>
#include <QCheckBox>

#include "chart_representation.h"
#include "../model/histogram.h"

#define TAB1_NAME "Histograma normal"
#define TAB2_NAME "Histograma acumulado"

#define R_CHK_NAME "Rojo"
#define G_CHK_NAME "Verde"
#define B_CHK_NAME "Azul"

#define TITLE "Histogramas"

class histogram_widget : public QWidget
{
  Q_OBJECT
private:
  chart_representation* chart_histogram;
  chart_representation* chart_ac_histogram;
  QTabWidget* tabs;
  QBoxLayout* layout;

  QCheckBox* red_chkbox;
  QCheckBox* green_chkbox;
  QCheckBox* blue_chkbox;
public:
  explicit histogram_widget(QWidget *parent = nullptr);

  const chart_representation* get_histogram () { return chart_histogram; }
  const chart_representation* get_ac_histogram () { return chart_ac_histogram; }

public slots:
  void update_charts (const histogram& hist);
};

#endif // HISTOGRAM_WIDGET_H
