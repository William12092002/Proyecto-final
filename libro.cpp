#include "libro.h"
#include "Enemigo.h"

using namespace std;






book::book (int x1,int y1, int w,  int h, QGraphicsItem *parent):fisica(x1,y1,w,h,this)
{
    this->y1=y1;
    anim_index = 0;
    cayendo = true;
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_0.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_1.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_2.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_3.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_4.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_5.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_6.png"));
    ani[0].push_back(QPixmap(":/imagenes/libro cayendo/sprite_7.png"));

    // set random postion
    setPos(x1,y1);
    setPixmap(QPixmap(":/imagenes/libro cayendo/sprite_0.png"));


    //conexion


    QTimer * timer1 = new QTimer();
    QTimer * tiempoC = new QTimer();

    connect(timer1,SIGNAL(timeout()),this,SLOT(move()));
    timer1->start(100);
    connect(tiempoC,SIGNAL(timeout()),this,SLOT(colision()));
    tiempoC->start(1);





}

void book::change_a()
{

    if (anim_index == 8) {
        anim_index = 0;
    }
    setPixmap(ani[0][anim_index]);
    anim_index++;
}

void book::move()
{
    if (cayendo) {
        if (pos().y() < y1+64) {
            setPos(this->QGraphicsItem::x(),this->QGraphicsItem:: y() + 8);
            change_a();
        }
        else {
            cayendo = false;
            setPixmap(QPixmap(":/imagenes/libro cayendo/sprite_0.png"));


        }

    }
}

void book::colision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(MyPlayer)){
            MyPlayer *jugador = dynamic_cast<MyPlayer *>(colliding_items[i]);
            jugador->setLibros(jugador->getNlibros()+1);


            scene()->removeItem(this);
            delete this;
        }
    }
}
