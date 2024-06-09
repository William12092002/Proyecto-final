
#include "crono.h"


cronometro::cronometro(int tiempo, QGraphicsItem *parent)
{
    taim = tiempo;
    setFont(QFont("Alagard",30));

    QString stringt = QString:: number(taim);
    setPlainText(stringt);
    connect(ti,SIGNAL(timeout()),this,SLOT(changeT()));
    ti->start(1000);
}

void cronometro::changeT()
{

    QString newTime = QString::number(taim -1);
    taim = newTime.toInt();
    if(newTime != "0"){
        setPlainText(newTime);
    }
    else{
        setPlainText("AJO mi vale se acabo el tiempo");
        delete this;
    }

}
