#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

class filter {
private:
  std::vector <std::vector <int>> kernel;
public:
  filter();
  filter(std::vector<std::vector<int>> k);
  inline unsigned get_size () const { return kernel.size(); }
  inline int get_element (unsigned i, unsigned j) const {
    if (i > kernel.size())
      i = 0;
    if (j > kernel.size())
      j = 0;
    return kernel[i][j];
  }
};

#endif // KERNEL_H
