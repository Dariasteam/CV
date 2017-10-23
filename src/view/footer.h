#ifndef FOOTER_H
#define FOOTER_H

#include <QWidget>
#include <QLabel>
#include <QString>
#include <QStatusBar>

#define X_STRING "x: "
#define Y_STRING "y: "
#define FORMAT_STRING "formato: "
#define SIZE_STRING "tamaño: "
#define R_VALUE "  R:"
#define G_VALUE "  G:"
#define B_VALUE "  B:"

class footer : public QStatusBar
{
  Q_OBJECT
private:
  QLabel* x_pixel_label;
  QLabel* y_pixel_label;
  QLabel* image_format;
  QLabel* image_size;
  QLabel* rgb_values;
public:
  explicit footer(QWidget *parent = nullptr);
public slots:
  void on_update_coordenate_labels (QPoint point);
  void on_update_meta_data (QString format, QSize size);  
  void on_update_rgb_at (QColor color);
signals:
  void get_rgb_at (QPoint);
};

#endif // FOOTER_H
