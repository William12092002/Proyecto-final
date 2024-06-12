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
#include<QMediaPlayer>
#include <QAudioOutput>

using namespace std;

class game:  public QGraphicsView{
 Q_OBJECT
public:

    game(QWidget * parent = 0);


private:

    QGraphicsScene * scenem ;
    QGraphicsScene * sceneMenu ;
    QGraphicsScene * scene1;
    MyPlayer *player;
    MyPlayer1 *player1;
    void setscene2();
    void setscene3(int n);
    int Level1Time = 44;
    int p = 0;
    QMediaPlayer * musica;
    QAudioOutput * controlM;

protected:

    void keyPressEvent(QKeyEvent * event) override;


public slots:

    void spawn();
    void spawnW();
    void  decrease();


};

#endif // GAME_H
