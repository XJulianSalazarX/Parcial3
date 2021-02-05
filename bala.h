#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <math.h>
#include <QTimer>
#include <QGraphicsScene>

class Bala: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bala(double posx_,double posy_,double v_inicial_,int angulo_,double distacia_);
    ~Bala();

private:
    double posx,posy,v_inicial,r_impacto,tiempo,g,distancia;
    int angulo;
    QTimer *timer;

public slots:
    void Mover();
};

#endif // BALA_H
