#ifndef CAMINO_H
#define CAMINO_H

#include <QGraphicsItem>
#include <QPainter>
//rastro que deja la bala
class Camino: public QGraphicsItem
{
public:
    Camino(double x, double y);
    ~Camino();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CAMINO_H
