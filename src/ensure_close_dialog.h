#ifndef ENSURE_CLOSE_DIALOG_H
#define ENSURE_CLOSE_DIALOG_H

#include <QDialog>
#include <QAction>
#include <QWidget>

class ensure_close_dialog : public QWidget
{
  Q_OBJECT
public:
  explicit ensure_close_dialog(QWidget *parent = nullptr);
  QAction* close_file_no_save;
  QAction* save_and_close_file;
  QAction* cancel;
signals:

public slots:
};

#endif // ENSURE_CLOSE_DIALOG_H
