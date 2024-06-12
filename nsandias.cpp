#include "nsandias.h"




Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    balas = 0;
    texto = "Proyectiles: " + QString::number(balas);
    // draw the text
    setPlainText(texto);
    setDefaultTextColor(Qt::black);
    setFont(QFont("Pixel Sans Serif Condensed",26));
}
void Score::setScore(int n){

    balas = n;
    texto = "Proyectiles: " + QString::number(balas);
    setPlainText(texto);
    setDefaultTextColor(Qt::black);
    setFont(QFont("Pixel Sans Serif Condensed",26));

}

void Score::decreaceS(){

    if(balas > 0){

        balas--;
        balas_= QString::number(balas);
        texto = "Proyectiles: " + balas_;
        setPlainText(texto);
        setDefaultTextColor(Qt::black);
        setFont(QFont("Pixel Sans Serif Condensed",26));
    }


}

