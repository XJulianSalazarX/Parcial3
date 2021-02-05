#include "bala.h"

Bala::Bala(double Xo_,double Yo_,double v_inicial_,int angulo_,double distacia_)
{
    setPixmap(QPixmap(":/images/canonbullet.png").scaled(20,20));
    Xo = Xo_;
    Yo = Yo_;
    posx = Xo;
    posy = 720-Yo;
    v_inicial = v_inicial_;
    angulo = angulo_;
    distancia = distacia_;
    g = 9.8;
    tiempo = 0;
    setPos(posx,posy);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    timer->start(10);
}

Bala::~Bala()
{
    delete timer;
}

void Bala::Mover()
{
    tiempo+=0.05;
    double Vx,Vy;
    Vx = v_inicial * cos(angulo*M_PI/180);
    Vy = v_inicial * sin(angulo*M_PI/180);
    posx = Xo + Vx * tiempo;
    posy = 720 - (Yo + Vy * tiempo - (0.5*g*tiempo*tiempo));
    setPos(posx,posy);
    if(posy > 720){
        scene()->removeItem(this);
        delete this;
        return;
    }

}
