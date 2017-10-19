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
  bttn_apply_operation->setDisabled(true);

  layout->addWidget(title_label,0,0);
  layout->addWidget(check_overwrite,2,0);
  layout->addWidget(check_preview,2,1);
  layout->addWidget(bttn_apply_operation,3,0,-1,0);

}

void operation_options_widget::on_set_widget(QWidget *wid) {
  if (content != nullptr)
    delete content;
  content = wid;
  layout->addWidget(content,1,0);

  bttn_apply_operation->setEnabled(true);
}

