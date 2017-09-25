#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QList>

#include "canvas_window.h"

class view : public QWidget {
  Q_OBJECT

private:
  QList <canvas_window*> canvas_list;

public:
  explicit view(QWidget *parent = nullptr);

signals:

public slots:
};

#endif // VIEW_H
