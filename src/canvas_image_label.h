#ifndef CANVAS_IMAGE_LABEL_H
#define CANVAS_IMAGE_LABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class canvas_image_label : public QLabel
{
  Q_OBJECT
public:
  explicit canvas_image_label(QPixmap& pixmap, QWidget *parent = nullptr);
private:
  void mouseMoveEvent(QMouseEvent* ev);
signals:
  void update_coordinates (short x, short y);
public slots:
};

#endif // CANVAS_IMAGE_LABEL_H
