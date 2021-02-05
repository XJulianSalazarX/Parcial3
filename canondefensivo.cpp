#include "canondefensivo.h"

CanonDefensivo::CanonDefensivo(double posx_, double posy_, short r_)
              :Canon(posx_,posy_,r_)
{

}

//QRectF CanonDefensivo::boundingRect() const
//{
//    return QRectF(-r,-r,2*r,2*r);
//}

//void CanonDefensivo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    option = nullptr;
//    widget = nullptr;
//    painter->setBrush(Qt::blue);
//    painter->drawEllipse(boundingRect().center(),50,50);
//    painter->setBrush(Qt::darkCyan);
//    painter->drawEllipse(boundingRect());
//}
