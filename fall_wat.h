#ifndef FALL_WAT_H
#define FALL_WAT_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <random>
#include "fisicas.h"
#include "playerFirst.h"
#include "player.h"



class fallOb: public fisica, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    fallOb(int x1,int y1,int w, int h, QGraphicsItem * parent=0);


private:

    QVector<QPixmap> ani[4];
    int anim_index=0;

public slots:

    void move();
    void change_a();
    void colision();
};

#endif // FALL_WAT_H
