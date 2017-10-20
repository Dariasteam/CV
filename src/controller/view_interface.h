#ifndef VIEW_INTERFACE_H
#define VIEW_INTERFACE_H

#include <QWidget>

class view_interface : public QWidget
{
  Q_OBJECT
public:
  view_interface (QWidget* parent) : QWidget (parent) {}
signals:
  virtual void update_inform () = 0;
public slots:
};

#endif // VIEW_INTERFACE_H
