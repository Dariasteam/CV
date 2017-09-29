#include "canvas_window.h"

canvas_window::canvas_window(unsigned id, QPixmap& pix, QWidget* parent) : QMdiSubWindow (parent, Qt::WindowSystemMenuHint),
                                                             ID (id)
{
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  QLabel* label = new QLabel (this);    
  label->setPixmap(pix);
  label->setMaximumSize(label->pixmap()->size());
  layout()->addWidget(label);

  //setFixedSize(label->size().width(), label->size().height() + 19);
}

void canvas_window::focusInEvent(QFocusEvent *focusInEvent) {
  emit set_active(ID);
}
