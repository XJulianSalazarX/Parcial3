#include "canonofensivo.h"
#include "widget.h"
#include <QDebug>

extern Widget *w;

CanonOfensivo::CanonOfensivo(double posx_, double posy_, short r_)
             :Canon(posx_,posy_,r_)
{
    portal2 = new Portal(posx,posy);
    portal2->setVisible(false);
}

void CanonOfensivo::stop()
{
    portal->stopBala();
}

bool CanonOfensivo::simularDispApoyo(double angulo, double XoE, double YoE, double ViE, double angE)
{
    //datos para bala enemiga
    double xE,yE,VxE,VyE;
    //daatos para bala ya disparada
    double xA,yA,VxA,VyA;
    //datos bala a disparar
    double x,y,Vx,Vy;
    double radio = distancia*0.005;
    //velocidad en x e y bala enemiga
    VxE = ViE*cos(angE*M_PI/180);
    VyE = ViE*sin(angE*M_PI/180);
    //velocidad en x e y bala aliada
    VxA = portal->getV_inicial()*cos(portal->getAngulo()*M_PI/180);
    VyA = portal->getV_inicial()*sin(portal->getAngulo()*M_PI/180);

    for(int inicial=50;inicial<400;inicial++){
        Vx = inicial*cos(angulo*M_PI/180);
        Vy = inicial*sin(angulo*M_PI/180);

        for(double t=0,tE=1,tA=3;t<20;t+=0.5,tE+=0.5,tA+=0.5){
            //posicion bala a disparar
            x = posx + Vx * t;
            y = posy + Vy*t - (0.5*9.8*t*t);
            //posicion bala enemiga
            xE = XoE + VxE* tE;
            yE = YoE + VyE*tE - (0.5*9.8*tE*tE);
            //posicion bala a proteger
            xA = posx + VxA* tA;
            yA = posy + VyA*tA - (0.5*9.8*tA*tA);

            //bala enemiga ya alcanzo a la bala a proteger
            if(sqrt(pow((xA-xE),2)+pow((yA-yE),2))<=distancia*0.05){
                qDebug() << "gana defensivo";
                break;
            }
            else if(sqrt(pow((x-xE),2)+pow((y-yE),2))<=radio and sqrt(pow((posx-xE),2)+pow((posy-yE),2))>distancia*0.05){
                qDebug() << "datos encontrados";
                if(y>0 and sqrt(pow((x-xA),2)+pow((y-yA),2))>radio){
                    portal2->setAngulo(angulo);
                    portal2->setV_inicial(inicial);
                    portal2->setDistacia(distancia);
                    portal2->setR_impacto(radio);
                    portal2->setT_max(t);
                    portal2->setIsOfensivo(true);
                    if(w->getBalas()== 0)
                        w->agregarTexto("No conseguido\n\n");
                    QString datos="Simulacion disparo de ayuda: "+QString::number(w->getBalas()+1);
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

void CanonOfensivo::disparoApoyo()
{
    portal2->setVisible(true);
    portal2->disparar();
}

void CanonOfensivo::addPortal2()
{
    scene()->addItem(portal2);
}

double CanonOfensivo::anguloBalaApoyo()
{
    return portal2->getAngulo();
}
