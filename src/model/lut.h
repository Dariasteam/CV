#ifndef LUT_H
#define LUT_H

#define DEPTH 256

#include <QObject>

#include <vector>
#include <functional>
#include <future>
#include <iostream>
#include <cmath>

#define N_THREADS 32

struct LUT {
  std::vector<double> r;
  std::vector<double> g;
  std::vector<double> b;
private:
  virtual void each_value_modificator(unsigned from, unsigned to,
                                      std::function<double (double)> lambda,
                                      std::vector<double> &vec);
public:
  LUT();
  virtual void each_value_modificator_r (std::function<double (double)> lambda);
  virtual void each_value_modificator_g (std::function<double (double)> lambda);
  virtual void each_value_modificator_b (std::function<double (double)> lambda);
  virtual void each_modificator_from_to (unsigned from, unsigned to,
                                         std::function<double (double)> lambda);
  static LUT* generate_lut () { return new LUT; }
};

#endif // LUT_H
