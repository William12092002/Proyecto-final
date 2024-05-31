#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include <QTimer>
#include <Qobject>

class game: public QGraphicsView{

public:
    game(QWidget * parent = 0);
    QGraphicsScene * scene = new QGraphicsScene();
    MyPlayer *player;

};

#endif // GAME_H
