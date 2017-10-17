#ifndef IMAGE_OPERATION_H
#define IMAGE_OPERATION_H

#include <QColor>

class Image_operation {

  virtual QColor operator () (QColor pix);
};

#endif // IMAGE_OPERATION_H
