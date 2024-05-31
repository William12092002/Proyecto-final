#include "Enemigo.h"
#include "qgraphicsscene.h"
#include <QTimer>
#include <random>
using namespace std;


Enemigo::Enemigo(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(300, 500);
    int rand2 = distrib(gen);
    // set random postion
    setPos(800,rand2);

    setRect(0,0,50,100);
    //conexion

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(70);
}

void Enemigo::move()
{
    //muevo el proyectil
    setPos(x()-2,y());
    if(pos().x()+100 == 0){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}
