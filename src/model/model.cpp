#include "model.h"

model::model() {

}

void model::load_image(const QString& file_name) {
  QImage* raw_image = new QImage(file_name);  
  add_image(new picture(raw_image));
}

void model::add_image(picture *pic) {
  unsigned key = picture_list.size();
  picture_list.insert(key,pic);
  active_picture = key;
}

void model::store_image(const QString& file_name, unsigned i) {
  picture_list[i]->get_image()->save(file_name);
}

void model::delete_imagepix_at(unsigned key) {
  auto it = picture_list.find(key);
  if (it == picture_list.end()) return;

  picture* aux = it.value();
  picture_list.remove(key);
  //delete aux;

  active_picture = picture_list.begin().key();

  cout << "Imagen eliminada\n";
}

picture* model::get_picture_at(int key) {
  if (key >= picture_list.size() || key < -1) return nullptr;
  if (key == -1)
    return picture_list[active_picture];
  else
    return picture_list[key];
}
