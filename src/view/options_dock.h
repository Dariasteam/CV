#ifndef OPTIONS_DOCK_H
#define OPTIONS_DOCK_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QWidget>

#include "histogram_widget.h"

class options_dock : public QDockWidget {
  histogram_widget* histogram_wid;
public:
  options_dock(QWidget* parent = nullptr);
  inline histogram_widget* get_histogram_wid () { return histogram_wid; }
};

#endif // OPTIONS_DOCK_H
