#include "canvas_window.h"

canvas_window::canvas_window(QWidget* parent) : QMdiSubWindow (parent)
{
  canv = new canvas(this);
  layout()->addWidget(canv);


}
