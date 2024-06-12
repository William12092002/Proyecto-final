#include "Enemigo.h"

using namespace std;


Enemigo::Enemigo(QGraphicsItem * parent):QObject(), QGraphicsPixmapItem(parent){

    musica = new QMediaPlayer();
    control = new QAudioOutput();
    anim_index = 0;
    vida = 3;
    enemi[0].push_back(QPixmap(":/imagenes/policia moviendose/sprite_0.png"));
    enemi[0].push_back(QPixmap(":/imagenes/policia moviendose/sprite_1.png"));
    enemi[0].push_back(QPixmap(":/imagenes/policia moviendose/sprite_2.png"));
    enemi[0].push_back(QPixmap(":/imagenes/policia moviendose/sprite_3.png"));
    enemi[1].push_back(QPixmap(":/imagenes/policia moviendose/policia quieto"));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(300, 482);
    int rand2 = distrib(gen);
    // set random postion
    setPos(800,rand2);

    setPixmap(QPixmap(":/imagenes/policia moviendose/sprite_0.png"));
    //conexion
    bulletTime = new QTimer();
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    connect(bulletTime,SIGNAL(timeout()),this,SLOT(shoot()));
    timer->start(70);
    bulletTime->start(3000);
}

void Enemigo::move()
{
    //muevo el proyectil
    setPos(x()-2,y());
    change_a();
    if(pos().x()+100 == 0){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}

void Enemigo::shoot()
{
    setPixmap(enemi[1][0]);
    proyectilE * proyectil1 = new proyectilE ();
    proyectil1->setPos(x(),y());
    scene()->addItem(proyectil1);
    musica->setSource(QUrl("qrc:/sounds/sonidos/disparo.mp3"));
    musica->setAudioOutput(control);
    musica->play();

}

void  Enemigo :: change_a(){

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(enemi[0][anim_index]);
    anim_index++;

}

void Enemigo::setVida(int _vida)
{
    vida = _vida;
}

int Enemigo::getVida()
{
    return vida;
}
