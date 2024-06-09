#ifndef PROYECTIL_H
#define PROYECTIL_H



#include <QGraphicsPixmapItem>
#include <QObject>
class proyectil :  public QObject, public QGraphicsPixmapItem{
  Q_OBJECT
public:
    proyectil(QGraphicsItem * parent =0);

private:
    QVector<QPixmap> anim[4];
    int anim_index;


public slots:
    void move();
    void changeA();
};

#endif // PROYECTIL_H
