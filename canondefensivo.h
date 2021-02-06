#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>
//cañon defensivo
class CanonDefensivo: public Canon
{
public:
    CanonDefensivo(double posx_,double posy_,short r_);
    ~CanonDefensivo();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    //simular disparo de defensa sin importar la integridad del otro cañon punto(3)
    bool SimularDispDefensivo(double angulo,double XoE,double YoE,double ViE,double angE);
    //simular disparo de defensa sin dañar la integridad del cañon punto(4)
    bool SimularDispDefensivo2(double angulo,double XoE,double YoE,double ViE,double angE);
    //llama al metodo stopBala de la clase Portal
    void stop();
};

#endif // CANONDEFENSIVO_H
