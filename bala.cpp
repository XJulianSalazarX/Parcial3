#include "bala.h"

Bala::Bala(double Xo_,double Yo_,double v_inicial_,int angulo_,double r_impacto_)
{
    Xo = Xo_;
    Yo = Yo_;
    posx = Xo;
    posy = 720-Yo;
    v_inicial = v_inicial_;
    angulo = angulo_;
    r_impacto = r_impacto_;
    //distancia = distacia_;
    g = 9.8;
    tiempo = 0;
    setPos(posx-10,posy-10);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    timer->start(10);
}

Bala::~Bala()
{
    delete timer;
}

QRectF Bala::boundingRect() const
{
    return QRectF(-2,-2,4,4);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setBrush(Qt::blue);
//    painter->drawEllipse(boundingRect().center(),150,150);
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());

}

void Bala::Mover()
{
    tiempo+=0.01;
    double Vx,Vy;
    Vx = v_inicial * cos(angulo*M_PI/180);
    Vy = v_inicial * sin(angulo*M_PI/180);
    posx = Xo + Vx * tiempo;
    posy = 720 - (Yo + Vy * tiempo - (0.5*g*tiempo*tiempo));
    setPos(posx-10,posy-10);
    if(posy > 720){
        scene()->removeItem(this);
        delete this;
        return;
    }

}
