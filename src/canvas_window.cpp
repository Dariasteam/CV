#include "canvas_window.h"

canvas_window::canvas_window(unsigned id, QPixmap& pix, QWidget* parent) : QMdiSubWindow (parent, Qt::WindowSystemMenuHint),
                                                                           ID (id)
{
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  QLabel* label = new QLabel (this);    
  label->setPixmap(pix);
  label->setMaximumSize(label->pixmap()->size());
  layout()->addWidget(label);

  setFixedSize(pix.size().width(), pix.height() + HEADER_BAR_SIZE);
}

void canvas_window::focusInEvent(QFocusEvent *focusInEvent) {
  emit set_active(ID);
}

void canvas_window::closeEvent(QCloseEvent *ev) {
  emit close(ID);
}
