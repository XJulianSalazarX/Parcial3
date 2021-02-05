#include "portal.h"

Portal::Portal(double posx_,double posy_,QObject *parent):QObject(parent)
{
    pixmap = new QPixmap(":/images/portal.png");
    col = 0;
    w = 203;
    h = 150;
    posx = posx_;
    posy = posy_;
    setPos(posx,720-posy);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(150);
}

Portal::~Portal()
{
    delete pixmap;
    delete timer;
}

QRectF Portal::boundingRect() const
{
    return QRectF(-w/2,-h/2,w,h);
}

void Portal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(-w/2,-h/2,*pixmap,col,0,w,h);
}

void Portal::actualizar()
{
    col += w;
    if(col >= 1624){
        col = 0;
    }
    this->update(-w/2,-h/2,w,h);
}
