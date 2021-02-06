#include "canon.h"
#include <QDebug>

Canon::Canon(double posx_,double posy_,short r_)
{
    posx = posx_;
    posy = posy_;
    r = r_;
    setPos(posx,720-posy);
    portal = new Portal(posx,posy);
    portal->setVisible(false);
}

Canon::~Canon()
{
    delete portal;
}

QRectF Canon::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Canon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect().center(),20,20);
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void Canon::generarDisparo()
{
    portal->setVisible(true);
    portal->disparar();
}

bool Canon::disparar(double x_, double y_,double angulo)
{
    double radio;
    radio = distancia*0.025;
    double Vx,Vy,x,y;

    for(int inicial=50;inicial<350;inicial++){
        Vx = inicial*cos(angulo*M_PI/180);
        Vy = inicial*sin(angulo*M_PI/180);
        for(double t=0;t<20;t+=0.5){
            x = posx + Vx * t;
            y = posy + Vy*t -(0.5*9.8*t*t);
            if(sqrt(pow((x-x_),2)+pow((y-y_),2)) <= radio){
                portal->setAngulo(angulo);
                portal->setV_inicial(inicial);
                portal->setDistacia(distancia);
                portal->setR_impacto(radio);
                portal->setT_max(t);
                return true;
            }
        }
    }
    return false;
}

void Canon::addPortal()
{
    scene()->addItem(portal);
}

void Canon::portalInvisible()
{
    portal->setVisible(false);
}

void Canon::setDistancia(double value)
{
    distancia = value;
}

double Canon::getPosx() const
{
    return posx;
}

void Canon::setPosx(double value)
{
    posx = value;
}

double Canon::getPosy() const
{
    return posy;
}

void Canon::setPosy(double value)
{
    posy = value;
}

double Canon::getAngulo() const
{
    return portal->getAngulo();
}

double Canon::getV_inicial() const
{
    return portal->getV_inicial();
}
