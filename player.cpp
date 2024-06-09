#include "player.h"
#include "proyectil.h"
#include "qgraphicsscene.h"
#include <QDebug>
#include <QKeyEvent>




MyPlayer::MyPlayer(QGraphicsItem *parent): QGraphicsPixmapItem(parent){


    setPixmap(QPixmap(":/imagenes/player caminando/sprite_0.png"));
    anim_index = 0;
    ai2 = 0;
    anim[0].push_back(QPixmap(":/imagenes/player caminando/sprite_0.png"));
    anim[0].push_back(QPixmap(":/imagenes/player caminando/sprite_1.png"));
    anim[0].push_back(QPixmap(":/imagenes/player caminando/sprite_2.png"));
    anim[0].push_back(QPixmap(":/imagenes/player caminando/sprite_3.png"));
    anim[1].push_back(QPixmap(":/imagenes/player izquierda/sprite_0.png"));
    anim[1].push_back(QPixmap(":/imagenes/player izquierda/sprite_1.png"));
    anim[1].push_back(QPixmap(":/imagenes/player izquierda/sprite_2.png"));
    anim[1].push_back(QPixmap(":/imagenes/player izquierda/sprite_3.png"));
    anim[2].push_back(QPixmap(":/imagenes/player respirando/sprite_0.png"));
    anim[2].push_back(QPixmap(":/imagenes/player respirando/sprite_1.png"));
    anim[2].push_back(QPixmap(":/imagenes/player respirando/sprite_2.png"));

    animacion = false;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(staticA()));
    timer->start(200);



}



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
            MoveLeft();

        }

    }
    else if(event->key() == Qt::Key_D){
        setPos(x()+10,y());
        Moveright();

    }
    else if(event->key() == Qt::Key_Space){
        //creo un proyectil

            proyectil * proyectil1 = new proyectil ();
            proyectil1->setPos(x(),y());
            scene()->addItem(proyectil1);


    }
}

void MyPlayer::Moveright()
{

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(anim[0][anim_index]);
    anim_index++;

}

void MyPlayer::MoveLeft()
{

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(anim[1][anim_index]);
    anim_index++;
}

void MyPlayer::setAnimacion(bool v){

    animacion = v;

}

void MyPlayer :: staticA(){
    if (ai2 == 3) {
        ai2 = 0;
    }
    setPixmap(anim[2][ai2]);
    ai2++;
}
