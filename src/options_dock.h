#ifndef OPTIONS_DOCK_H
#define OPTIONS_DOCK_H

#include <QWidget>
#include <QDockWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QWidget>

class options_dock : public QDockWidget {
public:
  options_dock(QWidget* parent = nullptr);
};

#endif // OPTIONS_DOCK_H
