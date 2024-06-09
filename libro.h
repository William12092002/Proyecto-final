#ifndef LIBRO_H
#define LIBRO_H



#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "fisicas.h"
#include "player.h"



class book: public fisica, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    book(int x1,int y1,int w, int h, QGraphicsItem * parent=0);


private:

    QVector<QPixmap> ani[4];
    int anim_index=0;
    bool cayendo;
    qreal y1;

public slots:


    void change_a();
    void move();
    void colision();

};



#endif // LIBRO_H
