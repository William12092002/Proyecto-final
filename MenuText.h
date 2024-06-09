#ifndef MENUTEXT_H
#define MENUTEXT_H

#include <QGraphicsTextItem>
#include <QFont>
#include <QTimer>
#include <QList>

class textoMenu: public QGraphicsTextItem{
  Q_OBJECT
public:

    textoMenu(QGraphicsItem * parent=0);
    void setTexto(QString _texto);
    void setPosi(int num1,int num2);
    void setTamano(int t);


private:

    QTimer * timer;
    QString texto;
    QList<QString> colores = {"black","yellow","black"};
    int numero;
    int tamano;
    QList<int> pos;


public slots:

    void changeColor();
};

#endif // MENUTEXT_H
