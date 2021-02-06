#include "bala.h"
#include "widget.h"
#include <QDebug>

extern Widget *w;

Bala::Bala(double Xo_,double Yo_,double v_inicial_,int angulo_,double r_impacto_,double t_max_,bool isOf)
{
    Xo = Xo_;
    Yo = Yo_;
    posx = Xo;
    posy = 720-Yo;
    v_inicial = v_inicial_;
    angulo = angulo_;
    qDebug() << angulo;
    r_impacto = r_impacto_;
    t_max = t_max_;
    radio = new Radio(r_impacto);
    g = 9.8;
    tiempo = 0;
    toScene = true;
    isOfensivo = isOf;
    setPos(posx,posy);
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Mover()));
    timer->start(10);
}

Bala::~Bala()
{
    delete timer;
    scene()->removeItem(radio);
    delete radio;
    qDebug() << rastro.size();
    for(Camino *i : rastro){
        scene()->removeItem(i);
        delete i;
    }
}

QRectF Bala::boundingRect() const
{
    return QRectF(-2,-2,4,4);
}

void Bala::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkCyan);
    painter->drawEllipse(boundingRect());

}

void Bala::stopTimer()
{
    timer->stop();
}

void Bala::Mover()
{
    tiempo+=0.01;
    if(tiempo >= 3 and tiempo <=3.01){
        w->quitarPortal();
    }

    double Vx,Vy;
    Vx = v_inicial * cos(angulo*M_PI/180);
    Vy = v_inicial * sin(angulo*M_PI/180);
    posx = Xo + Vx * tiempo;
    posy = 720 - (Yo + Vy * tiempo - (0.5*g*tiempo*tiempo));
    setPos(posx,posy);

    if(int(tiempo*10)%10==0){
        rastro.push_back(new Camino(posx,posy));
        scene()->addItem(rastro.last());
    }

    if(toScene){
        scene()->addItem(radio);
        toScene = false;
    }
    radio->posicion(posx,posy);
    if(tiempo >= t_max){
        w->nextVisible();
        if(!isOfensivo and (w->getPunto()== 3 or w->getPunto()==4)){
            timer->stop();
            w->stopOfensivo();
        }
        else if(w->getPunto() == 5){
            timer->stop();
            w->stopDefensivo();
            w->quitarPortal2();
        }
        else{
            timer->stop();
        }
    }
}
