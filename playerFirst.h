#ifndef PLAYERFIRST_H
#define PLAYERFIRST_H



#include <QTimer>
#include <QGraphicsPixmapItem>
#include <Qobject>

class MyPlayer1: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    void keyPressEvent(QKeyEvent * event);
    MyPlayer1(QGraphicsItem * parent =0);
    void Moveright();
    void MoveLeft();
    QTimer *timer;
    int proyec=0;
    int getproyec();

private:
    QVector<QPixmap> anim[4];   // animations
    int anim_index,ai2;
    bool animacion;
    void setAnimacion(bool v);


public slots:

    void staticA();
};
#endif // PLAYERFIRST_H
