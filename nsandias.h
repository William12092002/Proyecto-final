#ifndef SCORE_H

#define SCORE_H

#include <QGraphicsTextItem>
#include <QFont>

#include <QObject>

class Score: public QGraphicsTextItem{
    Q_OBJECT
public:
    Score(QGraphicsItem * parent=0);
    void setScore(int n);
    int getScore();
    void decreaceS();
private:
    int balas ;
    QString balas_;
    QString texto;

};


#endif // SCORE_H
