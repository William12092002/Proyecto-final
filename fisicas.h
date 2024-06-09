#ifndef FISICAS_H

#include <QObject>
#include <QTimer>
#include <QGraphicsPixmapItem>

#define time_period 10

class fisica : public QObject
{
    Q_OBJECT
public:
    fisica(int x, int y, int w, int h, QGraphicsPixmapItem *item);
    void set_movement_type(QString type);
private:
    int x_dimension, y_dimension, h, w;
    float x, y, vx, vy;
    QTimer *time;
    QGraphicsPixmapItem *item;
    QString type;

    float get_phisical_x(float x);
    float get_phisical_y(float y);
    float get_simulated_x(float x);
    float get_simulated_y(float y);
    void calculate_cinematics(float ax, float ay);
    void calculate_parabolic_dynamics();
    void calculate_MRU_dynamics();
    void set_initial_conditions(float x, float y, float vx, float vy);

private slots:
    void time_step();
};




#define FISICAS_H

#endif // FISICAS_H
