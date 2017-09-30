#include "model.h"

model::model() {

}

void model::load_image(QString file_name) {
  QImage* raw_image = new QImage();
  raw_image->load(file_name);
  image_list.push_back(new picture(raw_image));
}

void model::store_image(QString file_name, unsigned i) {
  image_list[i]->get_image()->save(file_name);
}

void model::delete_imagepix_at(unsigned i) {
  image_list.removeAt(i);  
  cout << "Imagen eliminada" << std::endl;
}

QImage* model::get_image_at(int i) {
  if (i >= image_list.size() || i < -1) return nullptr;
  if (i == -1)
    return image_list.back()->get_image();
  else
    return image_list[i]->get_image();
}

QPixmap*  model::get_pixmap_at(int i) {
  if (i >= image_list.size() || i < -1) return nullptr;
  if (i == -1)
    return image_list.back()->get_pixmap();
  else
    return image_list[i]->get_pixmap();
}
