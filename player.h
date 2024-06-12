#ifndef PLAYER_H
#define PLAYER_H



#include <QTimer>
#include <QGraphicsPixmapItem>
#include <Qobject>
#include <QList>
#include "playerFirst.h"
#include "nsandias.h"
#include <QCoreApplication>
#include <QGraphicsTextItem>

class MyPlayer: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:

    void keyPressEvent(QKeyEvent * event);
    MyPlayer(QGraphicsItem * parent =0);
    void Moveright();
    void MoveLeft();
    QTimer *timer,*check;
    int proyectiles = 0;
    void setProyec(int pr);
    void setVida(int vi);
    int getVida();
    int getNlibros();
    void setLibros(int l);
    void init();
    void init2();
    void init3();

private:
    QVector<QPixmap> anim[4];   // animations
    int anim_index,ai2;
    bool animacion;
    void setAnimacion(bool v);
    QGraphicsTextItem * vidaText;
    QGraphicsTextItem * proyecText;
    QGraphicsTextItem * libroT;
    QGraphicsTextItem * winText;

    int NLibros=0;
    int vida;
    void updateVidaText();
    void updateproyecText();
    void updatelibrosText();


    QList<QGraphicsItem*> colisiones = collidingItems();


public slots:

    void staticA();
    void quit();
    void win();

};

#endif // PLAYER_H
