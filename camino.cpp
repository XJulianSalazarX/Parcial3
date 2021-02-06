#include "camino.h"

Camino::Camino(double x, double y)
{
    setPos(x,y);
}

Camino::~Camino()
{

}

QRectF Camino::boundingRect() const
{
    return QRectF(-2,-2,4,4);
}

void Camino::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}
