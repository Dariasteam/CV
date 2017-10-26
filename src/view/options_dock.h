#ifndef OPTIONS_DOCK_H
#define OPTIONS_DOCK_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QWidget>
#include <QScrollArea>

#include "histogram_widget.h"
#include "image_info_widget.h"
#include "operation_options_widget.h"

class options_dock : public QDockWidget {
  histogram_widget* histogram_wid;
  operation_options_widget* operation_wid;
  image_info_widget* image_info_wid;
public:
  options_dock(QWidget* parent = nullptr);
  inline histogram_widget* get_histogram_wid () { return histogram_wid; }
  inline operation_options_widget* get_operation_wid () {return operation_wid; }
  inline image_info_widget* get_image_wid () { return image_info_wid; }
};

#endif // OPTIONS_DOCK_H
