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
/*
class image_canvas : public QLabel {
  Q_OBJECT
public:
  image_canvas (QPixmap& pix, QWidget* parent = nullptr) :
    QLabel (parent)
  {
    setPixmap(pix);
  }
};
*/
class canvas_image_label : public QLabel {
  Q_OBJECT
public:
  explicit canvas_image_label(QPixmap& pixmap, QWidget *parent = nullptr);
  //virtual void set_canvas (image_canvas* img_c);
  //image_canvas* get_pixmap () { return img_canvas; }
private:
  //image_canvas* img_canvas;
  //QBoxLayout* layout;
  void mouseMoveEvent(QMouseEvent *ev);
signals:
  void update_coordenates (QPoint);
};

#endif // CANVAS_IMAGE_LABEL_H
