#include "ensure_close_dialog.h"

ensure_close_dialog::ensure_close_dialog(QWidget *parent) : QWidget(parent) {
  setWindowTitle(tr("¿Estás seguro de querer cerrar este archivo?"));

}
