
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include <QTimer>
#include <Qobject>


game *juego;

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    juego = new game;
    juego-> show();




    return a.exec();

    //spawn enemies
}
