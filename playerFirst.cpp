#include "playerFirst.h"

#include "qgraphicsscene.h"
#include <QDebug>
#include <QKeyEvent>





MyPlayer1::MyPlayer1(QGraphicsItem *parent): QGraphicsPixmapItem(parent){


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



void MyPlayer1::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A){
        if(pos().x()!=0){
            setPos(x()-15,y());
            MoveLeft();
        }

    }
    else if(event->key() == Qt::Key_D){
        setPos(x()+15,y());
        Moveright();
    }

}

void MyPlayer1::Moveright()
{

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(anim[0][anim_index]);
    anim_index++;

}

void MyPlayer1::MoveLeft()
{

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(anim[1][anim_index]);
    anim_index++;
}

void MyPlayer1::setAnimacion(bool v){

    animacion = v;

}

void MyPlayer1 :: staticA(){
    if (ai2 == 3) {
        ai2 = 0;
    }
    setPixmap(anim[2][ai2]);
    ai2++;
}
