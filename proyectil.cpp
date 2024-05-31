#include "proyectil.h"
#include "Enemigo.h"
#include "qgraphicsscene.h"
#include <QTimer>

proyectil::proyectil(){

    setRect(0,0,20,20);
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
            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //muevo el proyectil
    setPos(x()+10,y());
    if(pos().x()>= 800){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}
