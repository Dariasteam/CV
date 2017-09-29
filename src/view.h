#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QList>
#include <QPixmap>

#include "canvas_window.h"


class view : public QWidget {
  Q_OBJECT

private:
  QList <canvas_window*> canvas_list;
  short active_canvas;
public:
  explicit view(QWidget *parent = nullptr);  
  inline unsigned get_active_canvas () { return active_canvas;}
  void add_canvas_window (QPixmap& pixmap);
public slots:
  void on_window_set_active (unsigned id);
  void on_windows_close (unsigned id);
signals:
  void delete_image (unsigned);
};

#endif // VIEW_H
