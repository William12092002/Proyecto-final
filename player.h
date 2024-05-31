#ifndef PLAYER_H
#define PLAYER_H



#include <QGraphicsRectItem>
#include <Qobject>

class MyPlayer: public QObject, public QGraphicsRectItem{
Q_OBJECT
public:

    void keyPressEvent(QKeyEvent * event);

public slots:

    void spawn();
};

#endif // PLAYER_H
