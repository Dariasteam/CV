#include "picture.h"

picture::picture(QImage* image) :
  raw_image (image)
{
  pixmap = new QPixmap();
  pixmap->convertFromImage(*image);
}
