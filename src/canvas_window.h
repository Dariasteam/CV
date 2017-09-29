#ifndef CANVAS_WINDOWS_H
#define CANVAS_WINDOWS_H

#include <QMdiSubWindow>
#include <QFocusEvent>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include <QSizePolicy>

#include "options_dock.h"

class canvas_window : public QMdiSubWindow {
  Q_OBJECT
private:  
  unsigned ID;
public:
  canvas_window(unsigned id, QPixmap& pixmap, QWidget* parent = nullptr);
signals:
  void set_active (unsigned id);
public slots:
  void focusInEvent(QFocusEvent *focusInEvent);


};

#endif // CANVAS_WINDOWS_H
