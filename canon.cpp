#include "canon.h"

Canon::Canon(double posx_,double posy_,short r_)
{
    posx = posx_;
    posy = 720-posy_;
    r = r_;
    setPos(posx,posy);
}

Canon::~Canon()
{

}

QRectF Canon::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Canon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}
