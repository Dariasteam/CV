#ifndef OPERATION_OPTIONS_WIDGET_H
#define OPERATION_OPTIONS_WIDGET_H

#include <QWidget>
#include <QBoxLayout>
#include <QLabel>
#include <QCheckBox>

#define TITLE "Opciones del filtro"
#define CHECK_OVERWRITE "Sobreescribir la imagen tras la operación"

class operation_options_widget : public QWidget
{
  Q_OBJECT
private:
  QBoxLayout* layout;
  QWidget* content;
  QCheckBox* check_overwrite;
public:
  explicit operation_options_widget(QWidget *parent = nullptr);

signals:

public slots:
  void on_set_widget (QWidget* wid);
};

#endif // OPERATION_OPTIONS_WIDGET_H
