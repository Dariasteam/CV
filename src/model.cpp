#include "model.h"

model::model() {

}

void model::load_image(QString file_name) {
  QImage* image = new QImage();
  QPixmap* pixmap = new QPixmap();

  image->load(file_name);
  pixmap->convertFromImage(*image);

  image_list.push_back(image);
  pixmap_list.push_back(pixmap);
}

void model::store_image(QString file_name, unsigned i) {
  image_list[i]->save(file_name);
}

void model::delete_imagepix_at(unsigned i) {
  image_list.removeAt(i);
  pixmap_list.removeAt(i);
  cout << "Imagen eliminada" << std::endl;
}

QImage* model::get_image_at(int i) {
  if (i >= image_list.size() || i < -1) return nullptr;
  if (i == -1)
    return image_list.back();
  else
    return image_list[i];
}

QPixmap*  model::get_pixmap_at(int i) {
  if (i >= pixmap_list.size() || i < -1) return nullptr;
  if (i == -1)
    return pixmap_list.back();
  else
    return pixmap_list[i];
}
