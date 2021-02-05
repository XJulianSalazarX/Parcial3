#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include <canon.h>

class CanonOfensivo: public Canon
{
public:
    CanonOfensivo(double posx_,double posy_,short r_);

//    QRectF boundingRect() const;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CANONOFENSIVO_H
