#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>
#include "../../controller/plugin_interface.h"

#define PAL_TXT "PAL"
#define NTSC_TXT "NTSC"

class M : public QWidget {
  Q_OBJECT
public:
  M (QWidget* parent) : QWidget (parent) {}
signals:
  virtual void update_inform () = 0;
};

class menu : public M {
  Q_OBJECT
private:
  QPushButton* bttn_PAL;
  QPushButton* bttn_NTSC;
public:
  explicit menu(QWidget *parent = nullptr);
  inline QPushButton* get_pal_bttn () { return bttn_PAL; }
  inline QPushButton* get_ntsc_bttn () { return bttn_NTSC; }
private slots:
  void set_ntsc_checked (bool);
  void set_pal_checked (bool);
signals:
  void pal (bool);
  void update_inform ();
};

#endif // MENU_H

