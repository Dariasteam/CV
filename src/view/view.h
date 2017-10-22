#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QList>
#include <QPixmap>
#include <QHash>

#include "canvas_window.h"
#include "footer.h"

class view : public QWidget {
  Q_OBJECT

private:
  QHash <unsigned, canvas_window*> canvas_list;
  short active_canvas;
  footer* foot;
public:
  explicit view(footer* foot, QWidget *parent = nullptr);
  inline unsigned get_active_picture_id () { return active_canvas;}
  canvas_window* get_active_canvas ();
  void add_canvas_window (QPixmap& pixmap, QString name);
  bool theres_active_window () { return active_canvas != -1; }
public slots:
  void on_window_set_active (unsigned key);
  void on_windows_close (unsigned key);
signals:
  void delete_image ();
  void no_image_focused();
  void image_focused(unsigned);
};

#endif // VIEW_H
