#include "canvas_window.h"

canvas_window::canvas_window(unsigned id, QPixmap& pix, footer* foot,
                             QString name, QWidget* parent) :
                             QMdiSubWindow (parent, Qt::WindowSystemMenuHint), ID (id)
{
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
  showed_image = new canvas_image_label(pix, this);

  setWindowTitle(name);

  connect(showed_image,SIGNAL(update_coordinates(short,short)),foot,SLOT(on_update_coordinate_labels(short,short)));

  layout()->addWidget(showed_image);

  setFixedSize(pix.size().width(), pix.height() + HEADER_BAR_SIZE);

}

void canvas_window::focusInEvent(QFocusEvent *focusInEvent) {
  emit set_active(ID);
}

void canvas_window::closeEvent(QCloseEvent *ev) {
  emit close(ID);
}

