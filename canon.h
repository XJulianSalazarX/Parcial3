#ifndef CANON_H
#define CANON_H

#include <QGraphicsItem>
#include <QPainter>
#include "portal.h"

class Canon: public QGraphicsItem
{
public:
    Canon(double posx_,double posy_,short r_);
    ~Canon();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generarDisparo();
    bool disparar(double x_, double y_,double angulo);
    void addPortal();
    void setDistancia(double value);

protected:
    short r;
    double posx,posy,distancia;
    Portal *portal;
};

#endif // CANON_H
