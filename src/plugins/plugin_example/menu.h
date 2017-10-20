#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QPushButton>
#include <QBoxLayout>

#define PAL_TXT "PAL"
#define NTSC_TXT "NTSC"

class menu : public QWidget {
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
};

#endif // MENU_H

