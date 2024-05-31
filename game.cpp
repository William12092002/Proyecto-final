#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <Qobject>

game :: game(QWidget * parent){

    //creo la escena y la hago de 800x600
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);

    //hago que la escena creada sea la visualizada
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //creo el jugador

    player = new MyPlayer();
    player->setRect(0,0,100,100);
    player->setPos(0,400);

    //enfoco al jugador

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //anado el jugador a la escena

    scene->addItem(player);

    // spawneo de enemigos

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(7000);

    show();

}
