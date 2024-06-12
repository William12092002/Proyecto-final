#ifndef CRONO_H
#define CRONO_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QList>

class cronometro: public QGraphicsTextItem{
    Q_OBJECT

public:

    cronometro (int tiempo,QGraphicsItem * parent=0);
    int taim;
private:

    QTimer * ti = new QTimer;

public slots:
    void changeT();

};

#endif // CRONO_H
