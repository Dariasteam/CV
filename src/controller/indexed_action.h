#ifndef INDEXEDACTION_H
#define INDEXEDACTION_H

#include <QObject>
#include <QWidget>
#include <QAction>

class indexed_action : public QAction
{
  Q_OBJECT
private:
  unsigned index;
public:
  indexed_action(const QString& tilte, unsigned i, QWidget* parent = nullptr);
private slots:
  void pressed_slot (bool);
signals:
  void pressed_signal (unsigned i);
};

#endif // INDEXEDACTION_H
