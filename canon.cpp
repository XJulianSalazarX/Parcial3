#include "canon.h"

Canon::Canon(double posx_,double posy_,short r_)
{
    posx = posx_;
    posy = posy_;
    r = r_;
    setPos(posx,720-posy);
    portal = new Portal(posx,posy);
    portal->setVisible(false);
}

Canon::~Canon()
{
    //delete portal;
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

void Canon::generarDisparo()
{
    portal->setVisible(true);
    portal->setAngulo(45);
    portal->setDistacia(distance);
    portal->setV_inicial(100);
    portal->disparar();
}

void Canon::addPortal()
{
    scene()->addItem(portal);
}
