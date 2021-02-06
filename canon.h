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
    void portalInvisible();
    void setDistancia(double value);

    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

    double getAngulo() const;
    double getV_inicial() const;

protected:
    short r;
    double posx,posy,distancia;
    Portal *portal;
};

#endif // CANON_H
