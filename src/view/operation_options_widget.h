#ifndef OPERATION_OPTIONS_WIDGET_H
#define OPERATION_OPTIONS_WIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

#define TITLE "Opciones del filtro"
#define CHECK_OVERWRITE "Sobreescribir la imagen"
#define CHECK_PREVIEW   "Previsualizar"
#define BTTN_APPLY      "Aplicar operación"

class operation_options_widget : public QWidget
{
  Q_OBJECT
private:
  QGridLayout* layout;
  QWidget* content;
  QCheckBox* check_overwrite;
  QCheckBox* check_preview;
  QPushButton* bttn_apply_operation;
public:
  explicit operation_options_widget(QWidget *parent = nullptr);

signals:

public slots:
  void on_set_widget (QWidget* wid);
};

#endif // OPERATION_OPTIONS_WIDGET_H
