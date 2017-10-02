#ifndef FOOTER_H
#define FOOTER_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QStatusBar>

#define X_STRING "x: "
#define Y_STRING "y: "
#define FORMAT_STRING "formato: "
#define SIZE_STRING "tamaño :"

class footer : public QStatusBar
{
  Q_OBJECT
private:
  QLabel* x_pixel_label;
  QLabel* y_pixel_label;
  QLabel* image_format;
  QLabel* image_size;
public:
  explicit footer(QWidget *parent = nullptr);

signals:

public slots:
  void on_update_x_label (unsigned);
  void on_update_y_label (unsigned);
  void on_update_meta_data (QString format, short height, short width);
};

#endif // FOOTER_H
