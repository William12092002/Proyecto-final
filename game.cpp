#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "fall_wat.h"
#include "player.h"
#include <QTimer>
#include "Enemigo.h"
#include <QImage>
#include "MenuText.h"
#include "qevent.h"




game :: game(QWidget * parent){

    //creo la escena y la hago de 800x600
    musica = new QMediaPlayer();
    controlM = new QAudioOutput();
    sceneMenu = new QGraphicsScene();

    sceneMenu->setSceneRect(0,0,800,600);

    setBackgroundBrush(QBrush(QImage(":/imagenes/escenarios/escenario1 (1)")));

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

    // muestro la escena
    sceneMenu->addItem(titulo);
    sceneMenu->addItem(titulo1);
    setScene(sceneMenu);



    musica->setSource(QUrl("qrc:/sounds/sonidos/menu.mp3"));
    musica->setAudioOutput(controlM);
    musica->play();

    show();


}



void game::setscene2()
{

    textoMenu * titulo1 = new textoMenu();
    titulo1->setTexto("atrapa las sandias");
    titulo1->setPosi(200,50);
    titulo1->setTamano(30);

    musica->stop();
    musica->setSource(QUrl("qrc:/sounds/sonidos/nivel1.mp3"));
    musica->setAudioOutput(controlM);
    musica->play();

    scene1 = new QGraphicsScene();
    scene1 ->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/imagenes/escenarios/imagen2")));
    //agrego cronometros
    cronometro * c1 = new cronometro(44);
    scene1->addItem(c1);
    scene1->addItem(titulo1);

    //hago que la escena creada sea la visualizada

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    player1 = new MyPlayer1();
    player1->setPos(0,400);
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();
    scene1->addItem(player1);
    QTimer * timer1 = new QTimer();
    QTimer * gametime = new QTimer();

    QObject::connect(timer1,SIGNAL(timeout()),this,SLOT(spawnW()));
    timer1->start(2000);
    QObject::connect(gametime,SIGNAL(timeout()),this,SLOT(decrease()));
    gametime->start(1000);

    setScene(scene1);



}

void game::setscene3(int n)
{


    musica->stop();
    int bullet = n;

    //creo la escena
    scenem = new QGraphicsScene();
    scenem->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/imagenes/escenarios/escenario 7")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);



    //creo el jugador

    player = new MyPlayer();
    player->setPos(0,400);
    player ->setProyec(bullet);

    //enfoco al jugador

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //anado el jugador a la escena

    scenem->addItem(player);
    player->init();
    player->init2();
    player->init3();

    // spawneo de enemigos

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
    timer->start(4000);

    setScene(scenem);
}

void game::decrease()
{
    if (Level1Time >= 0){

        Level1Time --;
    }
    if(Level1Time==0){

        p = player1->getproyec();
        qDebug()<<"Tengo "<<p;
        setscene3(p);
    }
}




void game::keyPressEvent(QKeyEvent *event)
{

    if (this->scene() == sceneMenu && event->key() == Qt::Key_P) {

         setscene2();
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

