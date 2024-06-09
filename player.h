#ifndef PLAYER_H
#define PLAYER_H



#include <QTimer>
#include <QGraphicsPixmapItem>
#include <Qobject>
#include <QList>


class MyPlayer: public QObject, public QGraphicsPixmapItem{
Q_OBJECT
public:

    void keyPressEvent(QKeyEvent * event);
    MyPlayer(QGraphicsItem * parent =0);
    void Moveright();
    void MoveLeft();
    QTimer *timer;
    int NLibros=0;
private:
    QVector<QPixmap> anim[4];   // animations
    int anim_index,ai2;
    bool animacion;
    void setAnimacion(bool v);

    QList<QGraphicsItem*> colisiones = collidingItems();


public slots:

    void staticA();
};

#endif // PLAYER_H
