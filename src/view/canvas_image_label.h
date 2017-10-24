#ifndef CANVAS_IMAGE_LABEL_H
#define CANVAS_IMAGE_LABEL_H

#include <QLabel>
#include <QFrame>
#include <QWidget>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPoint>
#include <QRect>
#include <QBoxLayout>
#include <QPainter>

class image_canvas : public QLabel {
  Q_OBJECT
public:
  image_canvas (QPixmap& pix, QWidget* parent = nullptr) :
    QLabel (parent)
  {
    setPixmap(pix);
  }
private:
};

class canvas_image_label : public QFrame {
  Q_OBJECT
public:
  explicit canvas_image_label(QPixmap& pixmap, QWidget *parent = nullptr);
  void set_canvas (image_canvas* img_c);
  image_canvas* get_canvas () { return img_canvas; }
private:
  image_canvas* img_canvas;
  QBoxLayout* layout;

  QPoint start_point;
  QPoint end_point;

  bool selecting;
  bool area_selected;

  void mousePressEvent(QMouseEvent *ev);
  void mouseReleaseEvent(QMouseEvent *ev);
  void mouseMoveEvent(QMouseEvent *ev);
  void paintEvent(QPaintEvent* ev) override;
signals:
  void update_coordenates (QPoint);
  void update_region (QPoint, QPoint);
};

#endif // CANVAS_IMAGE_LABEL_H
