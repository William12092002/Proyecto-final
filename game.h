#ifndef GAME_H
#define GAME_H

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "player.h"
#include "crono.h"
#include <QTimer>
#include <Qobject>
#include <random>
#include "playerFirst.h"
using namespace std;

class game:  public QGraphicsView{
 Q_OBJECT
public:

    game(QWidget * parent = 0);

    void setscene();
private:
    QGraphicsTextItem * titulo;
    QGraphicsTextItem * instrucciones;
    QGraphicsScene * scenem ;
    QGraphicsScene * sceneMenu ;
    QGraphicsScene * scene1;
    MyPlayer *player;
    MyPlayer1 *player1;
protected:

    void keyPressEvent(QKeyEvent * event) override;


public slots:

    void spawn();
    void spawnW();

};

#endif // GAME_H
