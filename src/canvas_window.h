#ifndef CANVAS_WINDOWS_H
#define CANVAS_WINDOWS_H

#include <QMdiSubWindow>
#include <QLayout>

#include "canvas.h"


class canvas_window : public QMdiSubWindow
{
  Q_OBJECT
private:
  canvas* canv;

public:
  canvas_window(QWidget* parent = nullptr);
};

#endif // CANVAS_WINDOWS_H
