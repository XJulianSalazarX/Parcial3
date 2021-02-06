#include "canon.h"
#include <QDebug>
#include "widget.h"

extern Widget *w;

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

    for(int inicial=50;inicial<300;inicial++){
        Vx = inicial*cos(angulo*M_PI/180);
        Vy = inicial*sin(angulo*M_PI/180);
        for(double t=0;t<20;t+=0.5){
            x = posx + Vx * t;
            y = posy + Vy*t -(0.5*9.8*t*t);
            if(sqrt(pow((x-x_),2)+pow((y-y_),2)) <= radio){
                if(t<3 and (w->getPunto()==3 or w->getPunto()==4))
                    break;
                else if(t<4 and w->getPunto()==5)
                    break;
                portal->setAngulo(angulo);
                portal->setV_inicial(inicial);
                portal->setDistacia(distancia);
                portal->setR_impacto(radio);
                portal->setT_max(t);
                portal->setIsOfensivo(true);
                QString datos="Simulacion: "+QString::number(w->getBalas()+1);
                datos+="\nCoordenadas de salida: ("+QString::number(posx);
                datos+=", "+QString::number(posy)+")\n";
                datos+="Velocidad inicial: "+QString::number(inicial)+"\n";
                datos+="Angulo de disparo: "+QString::number(angulo)+"\n";
                datos+="Tiempo en el que detona la bala: "+QString::number(t)+" seg.\n";
                datos+="Coordenas de detonacion: ("+QString::number(x);
                datos+=", "+QString::number(y)+")\n";
                datos+="Coordenadas Objetivo: ("+QString::number(x_);
                datos+=", "+QString::number(y_)+")\n";
                qDebug() << datos;
                w->agregarTexto(datos);
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
