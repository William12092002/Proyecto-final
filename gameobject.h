#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <Qobject>
#include <QGraphicsScene>
#include <QGraphicsView>

class gameob: public QObject{
 Q_OBJECT

public slots:
  void spawn();




};

#endif // GAMEOBJECT_H
