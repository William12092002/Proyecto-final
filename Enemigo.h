#ifndef ENEMIGO_H
#define ENEMIGO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "qgraphicsscene.h"
#include <QTimer>
#include <random>
#include "Enemy_proy.h"

class Enemigo :  public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    int hitCount=0;
    Enemigo(QGraphicsItem * parent=0);
    void change_a();
    void setVida(int _vida);
    int getVida();
private:

    QVector<QPixmap> enemi[4];
    QTimer * bulletTime ;
    int anim_index;
    int vida;


public slots:
    void move();
    void shoot();
};


#endif // ENEMIGO_H
