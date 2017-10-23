#include "operation_options_widget.h"

operation_options_widget::operation_options_widget(QWidget *parent) :
  QWidget(parent),
  content (nullptr)
{  
  layout = new QGridLayout (this);
  setLayout(layout);

  QLabel* title_label = new QLabel (TITLE,this);

  check_overwrite = new QCheckBox (CHECK_OVERWRITE,this);
  check_overwrite->setChecked(true);

  check_preview = new QCheckBox (CHECK_PREVIEW,this);
  check_preview->setChecked(true);

  bttn_apply_operation = new QPushButton (BTTN_APPLY, this);

  bttn_cancel_operation = new QPushButton (BTTN_CANCEL, this);

  layout->addWidget(title_label,0,0);
  layout->addWidget(check_overwrite,2,0);
  layout->addWidget(check_preview,2,1);
  layout->addWidget(bttn_apply_operation,3,0);
  layout->addWidget(bttn_cancel_operation,3,1);

  setEnabled(false);
}

void operation_options_widget::set_plugin_information(plugin_metainfo info) {
  check_preview->setEnabled(info.can_preview);
}

void operation_options_widget::on_set_widget(QWidget *wid) {
  wid->setVisible(true);
  content = wid;
  layout->addWidget(content,1,0,1,0);
  setEnabled(true);
}

void operation_options_widget::on_clear_widget() {
  if (content != nullptr) {
    layout->removeWidget(content);
    content->setVisible(false);
  }
  setEnabled(false);
  content = nullptr;
}
