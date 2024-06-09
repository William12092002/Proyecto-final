#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "fall_wat.h"
#include "player.h"
#include <QTimer>
#include "nsandias.h"
#include "Enemigo.h"
#include <QImage>
#include "MenuText.h"
#include "qevent.h"






game :: game(QWidget * parent){



    //creo la escena y la hago de 800x600
    scenem = new QGraphicsScene();
    sceneMenu = new QGraphicsScene();
    scene1 = new QGraphicsScene();
    scene1 ->setSceneRect(0,0,800,600);
    sceneMenu->setSceneRect(0,0,800,600);
    scenem->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/imagenes/escenarios/escenario 7")));

    //agrego cronometros
    cronometro * c1 = new cronometro(15);
    scene1->addItem(c1);

    //hago que la escena creada sea la visualizada

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //escena de menu
    textoMenu * titulo = new textoMenu();
    titulo->setTexto("OAKKKLAND");
    titulo->setPosi(40,50);
    titulo->setTamano(100);
    textoMenu * titulo1 = new textoMenu();
    titulo1->setTexto("presiona la tecla 'P' para jugar");
    titulo1->setPosi(180,300);
    titulo1->setTamano(20);


    sceneMenu->addItem(titulo);
    sceneMenu->addItem(titulo1);
    setScene(scene1);

    //agrego el score

    Score * score = new Score();
    scenem -> addItem(score);

    //creo el jugador

    player = new MyPlayer();
    player->setPos(0,400);

    player1 = new MyPlayer1();
    player1->setPos(0,400);

    //enfoco al jugador

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    //anado el jugador a la escena

    scenem->addItem(player);

    scene1->addItem(player1);

    // spawneo de enemigos

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(4000);

    //spawneo de watermelon

    QTimer * timer1 = new QTimer();
    QObject::connect(timer1,SIGNAL(timeout()),this,SLOT(spawnW()));
    timer1->start(2000);


    show();

}

void game::setscene()
{

}

void game::keyPressEvent(QKeyEvent *event)
{

    if (this->scene() == sceneMenu && event->key() == Qt::Key_P) {
        setScene(scene1);
    }
    // Llama al método base para manejar otros eventos de teclas
        QGraphicsView::keyPressEvent(event);

}

void game :: spawn(){
    // create an enemy
    Enemigo * enemy = new Enemigo();
    scenem->addItem(enemy);
}

void game::spawnW()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 700);
    int rand2 = distrib(gen);

    // create an enemy
    fallOb * w = new fallOb(rand2,0,800,600);
    scene1->addItem(w);

}

