#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>

class CanonDefensivo: public Canon
{
public:
    CanonDefensivo(double posx_,double posy_,short r_);

//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CANONDEFENSIVO_H
