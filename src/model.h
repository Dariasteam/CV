#ifndef MODEL_H
#define MODEL_H

#include <QImage>
#include <QPixmap>
#include <QList>
#include <QImageReader>
#include <iostream>

using namespace std;

class model {
private:
  QList<QImage*> image_list;
  QList<QPixmap*> pixmap_list;
  unsigned active_window;
public:
  model();

  void load_image (QString file_name);
  void store_image (QString file_name, unsigned i);
  void delete_imagepix_at (unsigned i);

  QImage* get_image_at (int i);
  QPixmap* get_pixmap_at (int i);


};

#endif // MODEL_H
