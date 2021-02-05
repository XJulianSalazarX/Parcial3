#include "canonofensivo.h"

CanonOfensivo::CanonOfensivo(double posx_, double posy_, short r_)
             :Canon(posx_,posy_,r_)
{

}

//QRectF CanonOfensivo::boundingRect() const
//{
//    return QRectF(-r,-r,2*r,2*r);
//}

//void CanonOfensivo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    option = nullptr;
//    widget = nullptr;
//    painter->setBrush(Qt::green);
//    painter->drawEllipse(boundingRect().center(),15,15);
//    painter->setBrush(Qt::darkCyan);
//    painter->drawEllipse(boundingRect());
//}
