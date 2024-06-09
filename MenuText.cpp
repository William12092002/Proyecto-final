#include "MenuText.h"



textoMenu::textoMenu(QGraphicsItem *parent):QGraphicsTextItem(parent){
    numero = 0;
    texto = "hola";
    tamano = 0;
    pos ={0,0};
    timer = new QTimer();
    setPlainText(texto);
    setFont(QFont("Alagard",tamano));
    setDefaultTextColor(Qt::black);
    setPos(pos[0],pos[1]);
    connect(timer,SIGNAL(timeout()),this,SLOT(changeColor()));
    timer->start(100);




}

void textoMenu::changeColor()
{
    setDefaultTextColor(colores[numero]);

    if(numero == 2){
        numero = 0;
    }
    numero++;
}

void textoMenu::setTexto(QString _texto)
{
    texto = _texto;
    setPlainText(texto);
}

void textoMenu::setPosi(int num1, int num2)
{
    pos[0]=num1;
    pos[1]=num2;
    setPos(pos[0],pos[1]);
}

void textoMenu::setTamano(int t)
{
    tamano = t ;
    setFont(QFont("Alagard",tamano));
}

