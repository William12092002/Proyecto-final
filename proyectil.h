#ifndef PROYECTIL_H
#define PROYECTIL_H


#include <QGraphicsRectItem>
#include <QObject>
class proyectil :  public QObject, public QGraphicsRectItem{
  Q_OBJECT
public:
    proyectil();
public slots:
    void move();
};

#endif // PROYECTIL_H
