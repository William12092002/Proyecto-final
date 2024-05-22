#include "player.h"
#include "proyectil.h"
#include "qgraphicsscene.h"
#include <QDebug>
#include <QKeyEvent>



void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_S){
        setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_A){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_D){
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Space){
        //creo un proyectil

            proyectil * proyectil1 = new proyectil ();
            proyectil1->setPos(x(),y());
            scene()->addItem(proyectil1);


    }
}
