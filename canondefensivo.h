#ifndef CANONDEFENSIVO_H
#define CANONDEFENSIVO_H
#include <canon.h>

class CanonDefensivo: public Canon
{
public:
    CanonDefensivo(double posx_,double posy_,short r_);
    ~CanonDefensivo();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    bool SimularDispDefensivo(double angulo,double XoE,double YoE,double ViE,double angE);
    bool SimularDispDefensivo2(double angulo,double XoE,double YoE,double ViE,double angE);
    void stop();
};

#endif // CANONDEFENSIVO_H
