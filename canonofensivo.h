#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include <canon.h>

class CanonOfensivo: public Canon
{
public:
    CanonOfensivo(double posx_,double posy_,short r_);

    void stop();
    bool simularDispApoyo(double angulo, double XoE, double YoE, double ViE, double angE);
    void disparoApoyo();
    void addPortal2();
    double anguloBalaApoyo();
private:
    Portal *portal2;
};

#endif // CANONOFENSIVO_H
