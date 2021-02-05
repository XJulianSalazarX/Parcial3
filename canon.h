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
    void addPortal();
protected:
    short r;
    double posx,posy,distance;
    Portal *portal;
};

#endif // CANON_H
