#include "operation.h"

operation::operation() :
  pal (true)
{}

bool operation::operator () (picture* image) {
  std::vector<double> transform;

  if (pal)
    transform = PAL;
  else
    transform = NTSC;

  QImage* img = image->get_image();
  QSize size = img->size();

  image->each_pixel_modificator([&](QColor pixel) -> QColor {
    unsigned gray = pixel.red()   * transform[0] +
                    pixel.green() * transform[1] +
                    pixel.blue()  * transform[2];

    return QColor(gray, gray, gray);
  });
  image->set_black_and_white(true);
  return true;
}

void operation::on_change_pal(bool p) {
  pal = p;
}

