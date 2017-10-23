#ifndef IMAGE_INFO_WIDGET_H
#define IMAGE_INFO_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QString>

#include <vector>

#include "../model/picture.h"

struct rgb_labels {
  QLabel* r;
  QLabel* g;
  QLabel* b;
};

class image_info_widget : public QWidget
{
  Q_OBJECT
private:
  QGridLayout* layout;

  rgb_labels brightness;
  rgb_labels contrast;
  rgb_labels range;

  QLabel* dynamic_range;
  QLabel* entropy;
public:
  explicit image_info_widget(QWidget *parent = nullptr);

public slots:
  void on_update_basic_info (const picture_basic_info& info);
  void on_clear_basic_info ();
};

#endif // IMAGE_INFO_WIDGET_H
