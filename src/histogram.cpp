#include "histogram.h"

histogram::histogram(QImage* image) :
  regular               (N_CHANELS * CHANEL_DEPTH),
  acumulated            (N_CHANELS * CHANEL_DEPTH),
  normalized_regular    (N_CHANELS * CHANEL_DEPTH),
  normalized_acumulated (N_CHANELS * CHANEL_DEPTH)
  {
    //for (unsigned i = 0; i < )

}
