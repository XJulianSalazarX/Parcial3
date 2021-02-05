#include "canon.h"

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
    //delete portal;
}

QRectF Canon::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void Canon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());
}

void Canon::generarDisparo()
{
    portal->setVisible(true);
//    portal->setAngulo(45);
//    portal->setDistacia(distancia);
//    portal->setV_inicial(100);
    portal->disparar();
}

bool Canon::disparar(double x_, double y_,double angulo)
{
    double radio;
    radio = distancia*0.025;
    double Vx,Vy,x,y;

    for(int inicial=50;inicial<350;inicial++){
        Vx = inicial*cos(angulo);
        Vy = inicial*sin(angulo);
        for(double t=0;t<100;t+=0.5){
            x = posx + Vx * t;
            y = posy + Vy*t -(0.5*9.8*t*t);
            if(sqrt(pow((x-x_),2)+pow((y-y_),2)) <= radio){
                portal->setAngulo(angulo*180/M_PI);
                portal->setV_inicial(inicial);
                portal->setDistacia(distancia);
                portal->setR_impacto(radio);
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

void Canon::setDistancia(double value)
{
    distancia = value;
}
