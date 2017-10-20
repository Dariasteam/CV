#ifndef OPERATION_OPTIONS_WIDGET_H
#define OPERATION_OPTIONS_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

#include "../controller/plugin_interface.h"

#define TITLE "Opciones del filtro"
#define CHECK_OVERWRITE "Sobreescribir la imagen"
#define CHECK_PREVIEW   "Previsualizar"
#define BTTN_APPLY      "Aplicar"
#define BTTN_CANCEL      "Cancelar"

class operation_options_widget : public QWidget
{
  Q_OBJECT
private:
  QGridLayout* layout;
  QWidget* content;
  QCheckBox* check_overwrite;
  QCheckBox* check_preview;
  QPushButton* bttn_apply_operation;
  QPushButton* bttn_cancel_operation;
public:
  explicit operation_options_widget(QWidget *parent = nullptr);

  inline QCheckBox  * get_overwrite () { return check_overwrite;       }
  inline QCheckBox  * get_preview   () { return check_preview;         }
  inline QPushButton* get_apply     () { return bttn_apply_operation;  }
  inline QPushButton* get_cancel    () { return bttn_cancel_operation; }

  void set_plugin_information (plugin_metainfo info);
signals:

public slots:
  void on_set_widget (QWidget* wid);
};

#endif // OPERATION_OPTIONS_WIDGET_H
