#include <QApplication>

#include "controller/controller.h"
#include <vector>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);    
  controller ctrller;
  return a.exec();
}
