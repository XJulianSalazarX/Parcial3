#include "radio.h"

Radio::Radio(double r_)
{
    r = r_;
}

Radio::~Radio()
{

}

QRectF Radio::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Radio::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::transparent);
    painter->drawEllipse(boundingRect());
}

void Radio::posicion(double posx, double posy)
{
    setPos(posx,posy);
}
