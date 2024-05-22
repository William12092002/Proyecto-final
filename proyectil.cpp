#include "proyectil.h"
#include "qgraphicsscene.h"
#include <QTimer>

proyectil::proyectil(){

    setRect(0,0,10,50);
    //conexion

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);
}

void proyectil::move()
{
    //muevo el proyectil
    setPos(x()+10,y());
    if(pos().x()>= 800){
        scene()->removeItem(this);
        delete this;
        qDebug()<<"R";
    }
}
