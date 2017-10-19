#include "operation_options_widget.h"

operation_options_widget::operation_options_widget(QWidget *parent) :
  QWidget(parent),
  content (nullptr)
{  
  layout = new QBoxLayout (QBoxLayout::TopToBottom, this);
  setLayout(layout);
  setMinimumSize(QSize(100,100));

  QLabel* title_label = new QLabel (TITLE,this);

  check_overwrite = new QCheckBox (CHECK_OVERWRITE,this);
  check_overwrite->setChecked(true);


  layout->addWidget(title_label);
  layout->addWidget(check_overwrite);
}

void operation_options_widget::on_set_widget(QWidget *wid) {
  if (content != nullptr) {
    layout->removeWidget(content);
    delete content;
  }
  content = wid;
  layout->addWidget(content);
}

