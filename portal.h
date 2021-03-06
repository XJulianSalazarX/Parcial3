#ifndef PORTAL_H
#define PORTAL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QGraphicsScene>
#include "bala.h"
//genera las balas
class Portal: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Portal(double posx_,double posy_,QObject *parent = nullptr);
    ~Portal();
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget);
    //instaciar la clase bala con parametros de salida
    void disparar();

    void setV_inicial(double value);

    void setAngulo(double value);

    void setDistacia(double value);

    void setR_impacto(double value);

    void setT_max(double value);

    double getV_inicial() const;

    double getAngulo() const;

    void setIsOfensivo(bool value);
    //detener el timer de la clase Bala
    void stopBala();
    //eliminar bala y rastro de esta
    void limpiarBala();

private:
    double w,h,col;
    double posx,posy,v_inicial,angulo,distacia,r_impacto,t_max;
    QPixmap *pixmap;
    QTimer *timer;
    Bala *bala;
    bool isOfensivo;

public slots:
    void actualizar();
};

#endif // PORTAL_H
