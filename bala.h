#ifndef BALA_H
#define BALA_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QTimer>
#include <QGraphicsScene>
#include "radio.h"

class Bala: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Bala(double Xo_,double Yo_,double v_inicial_,int angulo_,double r_impacto_,double t_max_);
    ~Bala();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    double Xo,Yo,posx,posy,v_inicial,r_impacto,tiempo,g,distancia,t_max;
    int angulo;
    QTimer *timer;
    Radio *radio;
    bool toScene;
public slots:
    void Mover();
};

#endif // BALA_H
