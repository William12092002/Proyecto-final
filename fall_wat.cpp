#include "fall_wat.h"
#include "playerFirst.h"

using namespace std;






fallOb::fallOb (int x1,int y1, int w,  int h, QGraphicsItem *parent):fisica(x1,y1,w,h,this)
{

    anim_index = 0;

    ani[0].push_back(QPixmap(":/imagenes/sandia/sprite_0.png"));
    ani[0].push_back(QPixmap(":/imagenes/sandia/sprite_1.png"));
    ani[0].push_back(QPixmap(":/imagenes/sandia/sprite_2.png"));
    ani[0].push_back(QPixmap(":/imagenes/sandia/sprite_3.png"));


    // set random postion
    setPos(x1,y1);

    setPixmap(QPixmap(":/imagenes/sandia/sprite_0.png"));
    //conexion

    QTimer * timer = new QTimer();
    QTimer * timer1 = new QTimer();
    move();
    connect(timer,SIGNAL(timeout()),this,SLOT(change_a()));
    timer->start(100);
    connect(timer1,SIGNAL(timeout()),this,SLOT(colision()));
    timer1->start(1);

}

void fallOb::change_a()
{

    if (anim_index == 4) {
        anim_index = 0;
    }
    setPixmap(ani[0][anim_index]);
    anim_index++;
}

void fallOb::colision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(MyPlayer1)){
            scene()->removeItem(this);
            delete this;
            qDebug()<<"deleted";
            return;

        }
    }
}

void fallOb::move()
{
    this->set_movement_type("parabolic");


    if(pos().y() == 600){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
        return;
    }
}

