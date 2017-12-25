#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>

#define INFO_TXT "Pulse aplicar para establecer la transformación "

class view_interface : public QWidget {
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
};

class menu : public view_interface {
  Q_OBJECT
private:
  QSpinBox* spin_width;
  QSpinBox* spin_height;
  QCheckBox* check_fixed_ratio;
  QCheckBox* check_bilinear_filter;
private slots:
  void on_width_updated (int i);
  void on_height_updated (int i);
  void on_check_fixed_ration_changed (bool b);
  void on_single_update (int);
public:
  explicit menu(QWidget *parent = nullptr);
  const QSpinBox* get_spin_width() { return spin_width; }
  const QSpinBox* get_spin_height() { return spin_height; }
  const QCheckBox* get_check_bilinear() { return check_bilinear_filter; }
signals:
  void updated_values (int, int);
};

#endif // MENU_H

