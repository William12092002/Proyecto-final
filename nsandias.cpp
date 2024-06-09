#include "nsandias.h"



Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 0;

    // draw the text
    setPlainText(QString("Sandias : "));
    setDefaultTextColor(Qt::black);
    setFont(QFont("Pixel Sans Serif Condensed",26));
}
void Score::setScore(){


}

int Score::getScore(){


}
