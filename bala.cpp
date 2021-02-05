#include "bala.h"

Bala::Bala(double posx_,double posy_,double v_inicial_,int angulo_,double distacia_)
{
    setPixmap(QPixmap(":/images/canonbullet.png"));
    posx = posx_;
    posy = posy_;
    v_inicial = v_inicial_;
    angulo = angulo_;
    distancia = distacia_;
    g = 9.8;
    tiempo = 0;
}

Bala::~Bala()
{

}

void Bala::Mover()
{

}
