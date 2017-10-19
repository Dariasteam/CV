#ifndef OPTIONS_DOCK_H
#define OPTIONS_DOCK_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QWidget>

#include "histogram_widget.h"
#include "operation_options_widget.h"

class options_dock : public QDockWidget {
  histogram_widget* histogram_wid;
  operation_options_widget* operation_wid;
public:
  options_dock(QWidget* parent = nullptr);
  inline histogram_widget* get_histogram_wid () { return histogram_wid; }
  inline operation_options_widget* get_operation_wid () {return operation_wid; }
};

#endif // OPTIONS_DOCK_H
