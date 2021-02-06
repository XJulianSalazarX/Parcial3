#ifndef RADIO_H
#define RADIO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

class Radio: public QGraphicsItem
{
public:
    Radio(double r_);
    ~Radio();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void posicion(double posx,double posy);
private:
    double r;
};

#endif // RADIO_H
