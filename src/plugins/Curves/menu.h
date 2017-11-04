#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QBoxLayout>
#include <QPixmap>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QPainter>
#include <QLabel>
#include <QObject>
#include <QtCharts>
#include <QChart>
#include <QStackedLayout>
#include <QSpinBox>

#include "model.h"

#define CLOSE_TXT "x"

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class point_representation : public QWidget {
  Q_OBJECT
private:
  QBoxLayout* layout;

  QSpinBox* x;
  QSpinBox* y;

  QPushButton* close_bttn;
public:
  explicit point_representation (QPoint p,
                                 bool closable,
                                 QWidget* parent = nullptr);
public slots:
  void on_set_values (unsigned x, unsigned y);
signals:
  void check_values (unsigned x, unsigned y);  
};

class curve_chart : public QChartView {
  Q_OBJECT
public :
  curve_chart (model* mdl);

  void mouseMoveEvent(QMouseEvent* ev);
  void mousePressEvent(QMouseEvent* ev);
  void mouseReleaseEvent(QMouseEvent* ev);  
signals:
  void update_point (QPoint original_coordenates, double factor);
  void chart_clicked (QPoint coordenates, double factor);
  void release ();
};

class menu : public view_interface {
  Q_OBJECT
private:
  model* mdl;
  QBoxLayout* layout;

  QWidget* labels_container;
  QWidget* chart_container;

  curve_chart chart_view;
  QChart chart;
  QLineSeries* chart_line_serie;
public slots:
  void on_update_points (QList<SyncPoint*> points);
public:
  explicit menu(model* m, QWidget *parent = nullptr);
signals:
  void update_lut (QList<SyncPoint*> points);
};

#endif // MENU_H

