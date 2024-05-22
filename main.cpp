
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //creo una escena

    QGraphicsScene * scene = new QGraphicsScene();

    //creo un item para añadir a la escena

    MyRect * player1 = new MyRect();
    player1 -> setRect(0,0,100,100); // configuro tamano del rectangulo

    //agrego el item a la escena

    scene->addItem(player1);

    //enfoco el item


    player1 ->setFlag(QGraphicsItem::ItemIsFocusable);
    player1 -> setFocus();


    //creo una vista para visualizar la escena

    QGraphicsView * vista =  new QGraphicsView(scene);
    vista->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    vista->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // muestro la vista

    vista -> show();
    vista->setFixedSize(800,600);
    scene ->setSceneRect(0,0,800,600);
    player1 ->setPos((vista->width()) - (vista->width()),vista->height()/2);


    //creo enemigos

    QTimer * timer2 = new QTimer();

    return a.exec();

    //spawn enemies
}
