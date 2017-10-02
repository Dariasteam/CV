#ifndef CANVAS_WINDOWS_H
#define CANVAS_WINDOWS_H

#include <QMdiSubWindow>
#include <QFocusEvent>
#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QLayout>
#include <QPixmap>
#include <QSizePolicy>
#include <QDebug>
#include <QCloseEvent>
#include <QString>

#include "options_dock.h"
#include "canvas_image_label.h"
#include "footer.h"

#define HEADER_BAR_SIZE 20

/* Representa una ventana flotante que muestra
 * una imagen abierta
 * */
class canvas_window : public QMdiSubWindow {
  Q_OBJECT
private:  
  unsigned ID;
  canvas_image_label* showed_image;
public:
  canvas_window(unsigned id, QPixmap& pixmap, footer* foot, QString name, QWidget* parent = nullptr);
signals:
  void set_active (unsigned id);
  void close (unsigned id);
public slots:
  void focusInEvent(QFocusEvent *focusInEvent);
private:
  void closeEvent(QCloseEvent* ev);  

};

#endif // CANVAS_WINDOWS_H
