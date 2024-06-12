#include "Enemy_proy.h"
#include "qgraphicsscene.h"


proyectilE::proyectilE(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    anim_index = 0;
    setPixmap(QPixmap(":/imagenes/bala /sprite_0.png"));
    anim[0].push_back(QPixmap(":/imagenes/bala/sprite_0.png"));
    anim[0].push_back(QPixmap(":/imagenes/bala/sprite_1.png"));
    anim[0].push_back(QPixmap(":/imagenes/bala/sprite_2.png"));
    anim[0].push_back(QPixmap(":/imagenes/bala/sprite_3.png"));
    anim[0].push_back(QPixmap(":/imagenes/bala/sprite_4.png"));
    anim[0].push_back(QPixmap(":/imagenes/bala/sprite_5.png"));


    //conexion
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);
}





void proyectilE::move()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(MyPlayer)){
            MyPlayer *jugador1 = dynamic_cast<MyPlayer *>(colliding_items[i]);
            jugador1->setVida(jugador1->getVida()-1);
            delete this;
            return;
        }
    }
    //muevo el proyectil
    setPos(x()-9,y());
    changeA();
    if(pos().x()<= 0){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}

void proyectilE::changeA(){

    if (anim_index == 6) {
        anim_index = 0;
    }
    setPixmap(anim[0][anim_index]);
    anim_index++;


}
