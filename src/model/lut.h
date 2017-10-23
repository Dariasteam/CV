#ifndef LUT_H
#define LUT_H

#define DEPTH 255

#include <vector>
#include <functional>
#include <QObject>

struct LUT {
  std::vector<double> r;
  std::vector<double> g;
  std::vector<double> b;
private:

  virtual void each_value_modificator(std::function<double (double)> lambda,
                              std::vector<double> &vec);

public:
  LUT();

  virtual void each_value_modificator_r (std::function<double (double)> lambda);
  virtual void each_value_modificator_g (std::function<double (double)> lambda);
  virtual void each_value_modificator_b (std::function<double (double)> lambda);

};

#endif // LUT_H
