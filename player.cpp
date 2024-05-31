#include "player.h"
#include "Enemigo.h"
#include "proyectil.h"
#include "qgraphicsscene.h"
#include <QDebug>
#include <QKeyEvent>



void MyPlayer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W){
        if(pos().y()+100!=400){
            setPos(x(),y()-10);
        }

    }
    else if(event->key() == Qt::Key_S){
        if(pos().y()+100!=600){
           setPos(x(),y()+10);
        }

    }
    else if(event->key() == Qt::Key_A){
        if(pos().x()!=0){
            setPos(x()-10,y());
        }

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

void MyPlayer :: spawn(){
    // create an enemy
    Enemigo * enemy = new Enemigo();
    scene()->addItem(enemy);
}
