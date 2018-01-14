#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

class filter {
private:
  std::vector <std::vector <int>> kernel;
public:
  filter();  
  filter(std::vector<std::vector<int>> k);

  inline unsigned get_y_size () const { return kernel.size(); }
  inline unsigned get_x_size () const { return kernel[0].size(); }

  inline int get_element (unsigned i, unsigned j) const {
    /*
    if (i > kernel[0].size())
      i = 0;
    if (j > kernel.size())
      j = 0;
      */
    return kernel[i][j];
  }
  static filter* generate_filter (std::vector<std::vector<int>> k) {
    return new filter (k);
  }
};

#endif // KERNEL_H
