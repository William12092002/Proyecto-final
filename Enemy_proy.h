#ifndef ENEMY_PROY_H
#define ENEMY_PROY_H


#include "player.h"
#include <QGraphicsPixmapItem>
#include <QObject>

class proyectilE :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    proyectilE(QGraphicsItem * parent =0);

private:
    QVector<QPixmap> anim[4];
    int anim_index;


public slots:
    void move();
    void changeA();
};

#endif // ENEMY_PROY_H
