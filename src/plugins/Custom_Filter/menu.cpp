#include "menu.h"

menu::menu(QWidget *parent) :
  view_interface(parent)
{
  layout = new QBoxLayout(QBoxLayout::TopToBottom, this);
  setLayout(layout);

  user_input = new QTextEdit (this);
  layout->addWidget(user_input);

  connect(user_input,SIGNAL(textChanged()),this,SLOT(check_kernel()));
}

void menu::check_kernel() {
  std::string text = user_input->toPlainText().toStdString();
  std::stringstream ss(text);
  std::string to;

  std::vector<std::vector<int>> vec;
  unsigned i = 0;

  if (!text.empty()) {
    while(std::getline(ss,to,'\n')){
      vec.resize(vec.size() + 1);
      std::stringstream ss2 (to);
      std::string aux;
      while(std::getline(ss2,aux,' ')){
        int n;
        try {
          n = std::stoi(aux);
        }
        catch (std::exception const & e) {
          return;
        }
        vec[i].push_back(n);
      }
      i++;
    }
  }

  unsigned size_y = vec.size();
  if (size_y == 0)
    return;

  unsigned size_x = vec[0].size();

  for (auto& row : vec) {
    if (row.size() != size_x)
      return;
  }

  if (size_y == 1 && size_x % 2 != 0 && size_x > 1)
    emit kernel_valid(vec);
  else if (size_x == 1 && size_y % 2 != 0 && size_y > 1)
    emit kernel_valid(vec);
  else if (size_y == size_x && size_x % 2 != 0 && size_x > 1)
    emit kernel_valid(vec);
  else
    return;


  std::cout << "Kernel válido" << std::endl;
}
