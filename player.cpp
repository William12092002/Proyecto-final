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
    vida = 3;
    animacion = false;
    timer = new QTimer(this);
    check = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(staticA()));
    timer->start(200);
    connect(check,SIGNAL(timeout()),this,SLOT(quit()));
    connect(check,SIGNAL(timeout()),this,SLOT(win()));
    check->start(1);



}
void MyPlayer::updateVidaText() {
    vidaText->setPlainText(QString("Vida: %1").arg(vida));
}

void MyPlayer::updateproyecText()
{
    proyecText->setPlainText(QString("Proyectiles: %1").arg(proyectiles));
}

void MyPlayer::updatelibrosText()
{
    libroT->setPlainText(QString("libros: %1").arg(NLibros));
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
    else if(event->key() == Qt::Key_Space ){
        //creo un proyectil
        if(proyectiles > 0){
            proyectil * proyectil1 = new proyectil ();
            proyectil1->setPos(x(),y());
            scene()->addItem(proyectil1);
            proyectiles--;
            updateproyecText();

        }



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

void MyPlayer::setProyec(int pr)
{
    proyectiles = pr;
}

void MyPlayer::setVida(int vi)
{
    vida = vi;
    updateVidaText();

}

int MyPlayer::getVida()
{
    return vida;
}

int MyPlayer::getNlibros()
{
    return NLibros;
}

void MyPlayer::setLibros(int l)
{
    NLibros = l;
    updatelibrosText();
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

void MyPlayer::init() {
    vidaText = new QGraphicsTextItem();
    vidaText->setDefaultTextColor(Qt::red);
    vidaText->setFont(QFont("Alagard",16));
    vidaText->setPos(10, 10); // Ajusta la posición según tus necesidades
    scene()->addItem(vidaText);
    updateVidaText();
}

void MyPlayer::init2()
{

    proyecText = new QGraphicsTextItem();
    proyecText->setDefaultTextColor(Qt::darkGreen);
    proyecText->setFont(QFont("Alagard",16));
    proyecText->setPos(10, 40); // Ajusta la posición según tus necesidades
    scene()->addItem(proyecText);
    updateproyecText();

}

void MyPlayer::init3()
{

    libroT = new QGraphicsTextItem();
    libroT->setDefaultTextColor(Qt::darkGreen);
    libroT->setFont(QFont("Alagard",16));
    libroT->setPos(10, 80); // Ajusta la posición según tus necesidades
    scene()->addItem(libroT);
    updatelibrosText();
}


void MyPlayer::quit()
{
    if(vida == 0){
        QGraphicsTextItem* gameOverText = new QGraphicsTextItem("Game Over");
        gameOverText->setDefaultTextColor(Qt::red);
        gameOverText->setFont(QFont("Alagard",100));
        scene()->addItem(gameOverText);
        gameOverText->setPos(scene()->width()/2 - gameOverText->boundingRect().width()/2, scene()->height()/2 - gameOverText->boundingRect().height()/2);
        QTimer::singleShot(800, qApp, SLOT(quit()));
    }
}

void MyPlayer::win()
{

    if(NLibros == 10){
        winText = new QGraphicsTextItem("Ganaste");
        winText->setDefaultTextColor(Qt::darkYellow);
        winText->setFont(QFont("Alagard",100));
        scene()->addItem(winText);
        winText->setPos(scene()->width()/2 - winText->boundingRect().width()/2, scene()->height()/2 - winText->boundingRect().height()/2);
        QTimer::singleShot(1000, qApp, SLOT(quit()));
    }
}
