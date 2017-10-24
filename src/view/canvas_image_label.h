#ifndef CANVAS_IMAGE_LABEL_H
#define CANVAS_IMAGE_LABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QPainter>

class canvas_image_label : public QLabel {
  Q_OBJECT
public:
  explicit canvas_image_label(QPixmap& pixmap, QWidget *parent = nullptr);
private:
  QPoint start_point;
  QPoint end_point;

  bool selecting;
  bool area_selected;

  void mouseMoveEvent(QMouseEvent* ev);
  void mousePressEvent(QMouseEvent *ev);
  void mouseReleaseEvent(QMouseEvent *ev);
  void paintEvent(QPaintEvent* ev) override;
signals:
  void update_coordenates (QPoint);
  void update_region (QPoint, QPoint);
};

#endif // CANVAS_IMAGE_LABEL_H
