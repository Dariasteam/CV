#include "indexed_action.h"

#include <iostream>

indexed_action::indexed_action(const QString& title, unsigned i, QWidget* parent) :
  QAction (title, parent),
  index (i)
{
  connect(this,SIGNAL(triggered(bool)),this,SLOT(pressed_slot(bool)));
}

void indexed_action::pressed_slot(bool) {
  emit pressed_signal(index);
}
