#ifndef CANON_H
#define CANON_H

#include <QGraphicsItem>
#include <QPainter>

class Canon: public QGraphicsItem
{
public:
    Canon(double posx_,double posy_,short r_);
    ~Canon();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

private:
    short r;
    double posx,posy,distance;
};

#endif // CANON_H
