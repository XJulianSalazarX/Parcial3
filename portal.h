#ifndef PORTAL_H
#define PORTAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include  <QGraphicsScene>

class Portal: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Portal(double posx_,double posy_,QObject *parent = nullptr);
    ~Portal();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
private:
    double w,h,col;
    double posx,posy;
    QPixmap *pixmap;
    QTimer *timer;

public slots:
    void actualizar();
};

#endif // PORTAL_H
