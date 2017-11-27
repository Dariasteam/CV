#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

class kernel {
private:
  std::vector <std::vector <int>> content;
public:
  kernel();
  kernel(std::vector<std::vector<int>> k);
};

#endif // KERNEL_H
