#ifndef OPTIONS_DOCK_H
#define OPTIONS_DOCK_H

#include <QWidget>
#include <QDockWidget>

class options_dock : public QDockWidget {
public:
  options_dock(QWidget* parent = nullptr);
};

#endif // OPTIONS_DOCK_H
