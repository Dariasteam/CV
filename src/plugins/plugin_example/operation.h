#ifndef OPERATION_H
#define OPERATION_H

#include <vector>

#include "../../controller/plugin_interface.h"

class operation : public image_operation
{  
private:
  const std::vector<double> NTSC = { 0.299, 0.587, 0.114 };
  const std::vector<double> PAL  = { 0.222, 0.707, 0.071 };

  bool pal;
public:
  operation();
  virtual bool operator () (picture* image);
public slots:
  void on_change_pal (bool p);
};


#endif // OPERATION_H

