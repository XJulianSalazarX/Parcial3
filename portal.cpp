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

void Portal::disparar()
{
    bala = new Bala(posx,posy,v_inicial,angulo,r_impacto,t_max,isOfensivo);
    scene()->addItem(bala);
}

void Portal::setV_inicial(double value)
{
    v_inicial = value;
}

void Portal::setAngulo(double value)
{
    angulo = value;
}

void Portal::setDistacia(double value)
{
    distacia = value;
}

void Portal::setR_impacto(double value)
{
    r_impacto = value;
}

void Portal::setT_max(double value)
{
    t_max = value;
}

double Portal::getV_inicial() const
{
    return v_inicial;
}

double Portal::getAngulo() const
{
    return angulo;
}

void Portal::setIsOfensivo(bool value)
{
    isOfensivo = value;
}

void Portal::stopBala()
{
    bala->stopTimer();
}

void Portal::actualizar()
{
    col += w;
    if(col >= 1624){
        col = 0;
    }
    this->update(-w/2,-h/2,w,h);
}
