#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H

#include <canon.h>
//cañon ofensivo
class CanonOfensivo: public Canon
{
public:
    CanonOfensivo(double posx_,double posy_,short r_);
    ~CanonOfensivo();

    //llama al metodo stopBala() de la clase Portal
    void stop();
    //simular disparo para defender la bala lanzada de la bala de defensa
    bool simularDispApoyo(double angulo, double XoE, double YoE, double ViE, double angE);
    //Disparo para defender la bala previamente lanzada
    void disparoApoyo();
    //agregar portal2 a la escenea
    void addPortal2();
    //retorna un double que corresponde al angulo de la bala del portal2
    double anguloBalaApoyo();
    //eliminar la bala y rastro hechas por portal2
    void limpiarPortal2();
    //hacer invisible en la escena el portal
    void portalInvisible2();
private:
    Portal *portal2;
};

#endif // CANONOFENSIVO_H
