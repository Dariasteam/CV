#include "model.h"

model::model() {

}

void model::load_image(const QString& file_name) {
  QImage* raw_image = new QImage(file_name);  
  picture_list.push_back(new picture(raw_image));
}

void model::store_image(const QString& file_name, unsigned i) {
  picture_list[i]->get_image()->save(file_name);
}

void model::delete_imagepix_at(unsigned i) {
  picture_list.removeAt(i);
  cout << "Imagen eliminada\n";
}

picture* model::get_picture_at(int i) {
  if (i >= picture_list.size() || i < -1) return nullptr;
  if (i == -1)
    return picture_list.back();
  else
    return picture_list[i];
}

