#include "canondefensivo.h"

CanonDefensivo::CanonDefensivo(double posx_, double posy_, short r_)
              :Canon(posx_,posy_,r_)
{

}

void CanonDefensivo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect().center(),20,20);
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}
