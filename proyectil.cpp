#include "proyectil.h"
#include "Enemigo.h"
#include "libro.h"

#include "qgraphicsscene.h"
#include <QTimer>

proyectil::proyectil(QGraphicsItem *parent): QGraphicsPixmapItem(parent){

    anim_index = 0;
    setPixmap(QPixmap(":/imagenes/sandia /sprite_0.png"));
    anim[0].push_back(QPixmap(":/imagenes/sandia/sprite_0.png"));
    anim[0].push_back(QPixmap(":/imagenes/sandia/sprite_1.png"));
    anim[0].push_back(QPixmap(":/imagenes/sandia/sprite_2.png"));
    anim[0].push_back(QPixmap(":/imagenes/sandia/sprite_3.png"));

    //conexion
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);
}





void proyectil::move()
{

    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemigo)){
            Enemigo *enemigo = dynamic_cast<Enemigo *>(colliding_items[i]);

            enemigo->hitCount++;
            // if enemy has been hit 3 times, remove it
            if (enemigo->hitCount >= 3) {
                int eX= enemigo->pos().x(), eY = enemigo->pos().y();
                scene()->removeItem(enemigo);
                delete enemigo;

                book *libro1 = new book(eX, eY, 800, 600);
                scene()->addItem(libro1);
            }
            // remove the projectile
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    //muevo el proyectil
    setPos(x()+10,y());
    changeA();
    if(pos().x()>= 800){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}

void proyectil::changeA(){

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(anim[0][anim_index]);
    anim_index++;


}
