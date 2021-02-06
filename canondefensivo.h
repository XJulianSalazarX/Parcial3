#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>

class CanonDefensivo: public Canon
{
public:
    CanonDefensivo(double posx_,double posy_,short r_);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    bool SimularDispDefensivo(double angulo,double XoE,double YoE,double ViE,double angE);
    bool SimularDispDefensivo2(double angulo,double XoE,double YoE,double ViE,double angE);
};

#endif // CANONDEFENSIVO_H
