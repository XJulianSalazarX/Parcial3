#ifndef CANON_H
#define CANON_H

#include <QGraphicsItem>
#include <QPainter>
#include "portal.h"

class Canon: public QGraphicsItem
{
public:
    Canon(double posx_,double posy_,short r_);
    ~Canon();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void generarDisparo();
    //retorna true si dado un angulo encuentra una velocidad inicial para destruir el objetivo que recibe
    bool disparar(double x_, double y_,double angulo);
    //añadir atributo portal a scene
    void addPortal();
    //portal invisible en la escene
    void portalInvisible();
    //limbiar bala y rastro
    void limpiarPortal();
    void setDistancia(double value);

    double getPosx() const;
    void setPosx(double value);

    double getPosy() const;
    void setPosy(double value);

    //retorna un double que representa el angulo de disparo de la bala
    double getAngulo() const;
    //retorna un double que representa la velocidad inicial de la bala
    double getV_inicial() const;

protected:
    short r;
    double posx,posy,distancia;
    Portal *portal;
};

#endif // CANON_H
