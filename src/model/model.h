#ifndef MODEL_H
#define MODEL_H

#include <QImage>
#include <QPixmap>
#include <QList>
#include <QImageReader>

#include <iostream>

#include "picture.h"
#include "histogram.h"

using namespace std;

class model {
private:
  QList<picture*> image_list;  
  unsigned active_window;
public:
  model();

  void load_image (QString file_name);
  void store_image (QString file_name, unsigned i);
  void delete_imagepix_at (unsigned i);

  picture* get_picture_at (int i);
};

#endif // MODEL_H
