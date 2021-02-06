#include "canondefensivo.h"
#include "widget.h"

extern Widget *w;

CanonDefensivo::CanonDefensivo(double posx_, double posy_, short r_)
              :Canon(posx_,posy_,r_)
{

}

CanonDefensivo::~CanonDefensivo()
{

}

void CanonDefensivo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect().center(),20,20);
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

bool CanonDefensivo::SimularDispDefensivo(double angulo, double XoE, double YoE, double ViE, double angE)
{
    double Vx=0,Vy=0,x=0,y=0,xE=0,yE=0,VxE=0,VyE=0;
    double radio = distancia*0.05;
    //velocidad en x e y bala enemiga
    VxE = ViE*cos(angE*M_PI/180);
    VyE = ViE*sin(angE*M_PI/180);
    for(int inicial=50;inicial<350;inicial++){
        Vx = inicial*cos(angulo*M_PI/180);
        Vy = inicial*sin(angulo*M_PI/180);
        for(double t=0,tE=2;t<20;t+=0.5,tE+=0.5){
            x = posx + Vx * t;
            y = posy + Vy*t -(0.5*9.8*t*t);
            xE = XoE + VxE* tE;
            yE = YoE + VyE*tE-(0.5*9.8*tE*tE);
            if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=radio and sqrt(pow((posx-xE),2)+pow((posy-yE),2))>radio){
                if(y>0){
                    portal->setAngulo(angulo);
                    portal->setV_inicial(inicial);
                    portal->setDistacia(distancia);
                    portal->setR_impacto(radio);
                    portal->setT_max(t);
                    portal->setIsOfensivo(false);
                    if(w->getBalas()== 0)
                        w->agregarTexto("No conseguido\n\n");
                    QString datos="Simulacion defensa: "+QString::number(w->getBalas()+1);
                    datos+="\nCoordenadas de salida: ("+QString::number(posx);
                    datos+=", "+QString::number(posy)+")\n";
                    datos+="Velocidad inicial: "+QString::number(inicial)+"\n";
                    datos+="Angulo de disparo: "+QString::number(angulo)+"\n";
                    datos+="Tiempo en el que detona la bala: "+QString::number(t)+" seg.\n";
                    datos+="Coordenas de detonacion: ("+QString::number(x);
                    datos+=", "+QString::number(y)+")\n";
                    datos+="Coordenadas Objetivo: ("+QString::number(xE);
                    datos+=", "+QString::number(yE)+")\n";
                    w->agregarTexto(datos);
                    return true;
                }
            }
        }
    }
    return false;
}

bool CanonDefensivo::SimularDispDefensivo2(double angulo, double XoE, double YoE, double ViE, double angE)
{
    double Vx=0,Vy=0,x=0,y=0,xE=0,yE=0,VxE=0,VyE=0;
    double radio = distancia*0.05;
    //velocidad en x e y bala enemiga
    VxE = ViE*cos(angE*M_PI/180);
    VyE = ViE*sin(angE*M_PI/180);
    for(int inicial=50;inicial<200;inicial++){
        Vx = inicial*cos(angulo*M_PI/180);
        Vy = inicial*sin(angulo*M_PI/180);
        for(double t=0,tE=2;t<20;t+=0.5,tE+=0.5){
            x = posx + Vx * t;
            y = posy + Vy*t -(0.5*9.8*t*t);
            xE = XoE + VxE* tE;
            yE = YoE + VyE*tE-(0.5*9.8*tE*tE);
            if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=radio and sqrt(pow((posx-xE),2)+pow((posy-yE),2))>radio){
                if(y>0 and sqrt(pow((x-XoE),2)+pow((y-YoE),2))>radio){
                    portal->setAngulo(angulo);
                    portal->setV_inicial(inicial);
                    portal->setDistacia(distancia);
                    portal->setR_impacto(radio);
                    portal->setT_max(t);
                    portal->setIsOfensivo(false);
                    if(w->getBalas()== 0)
                        w->agregarTexto("No conseguido\n\n");
                    QString datos="Simulacion defensa: "+QString::number(w->getBalas()+1);
                    datos+="\nCoordenadas de salida: ("+QString::number(posx);
                    datos+=", "+QString::number(posy)+")\n";
                    datos+="Velocidad inicial: "+QString::number(inicial)+"\n";
                    datos+="Angulo de disparo: "+QString::number(angulo)+"\n";
                    datos+="Tiempo en el que detona la bala: "+QString::number(t)+" seg.\n";
                    datos+="Coordenas de detonacion: ("+QString::number(x);
                    datos+=", "+QString::number(y)+")\n";
                    datos+="Coordenadas Objetivo: ("+QString::number(xE);
                    datos+=", "+QString::number(yE)+")\n";
                    w->agregarTexto(datos);
                    return true;
                }
            }
        }
    }
    return false;
}

void CanonDefensivo::stop()
{
    portal->stopBala();
}
