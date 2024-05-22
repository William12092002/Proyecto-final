#include "Enemigo.h"
#include "qgraphicsscene.h"
#include <QTimer>
#include <stdlib.h>  // rand()-> devuelve un entero muy grande
Enemigo::Enemigo(){
    // set random postion
    int rand1 = rand() % 700,rand2 = rand() %700;

    setPos(rand1,rand2);

    setRect(0,0,100,100);
    //conexion

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);
}

void Enemigo::move()
{
    //muevo el proyectil
    setPos(x()+10,y());
    if(pos().x()>= 800){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}
