#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QPixmap>

class picture {
private:
  QImage* raw_image;
  QPixmap* pixmap;
public:  
  picture (QImage* image);
  inline QImage*  get_image  () { return raw_image; }
  inline QPixmap* get_pixmap () { return pixmap;    }
};

#endif // IMAGE_H
