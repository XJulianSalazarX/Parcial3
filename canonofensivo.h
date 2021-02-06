#ifndef CANONOFENSIVO_H
#define CANONOFENSIVO_H
#include <canon.h>

class CanonOfensivo: public Canon
{
public:
    CanonOfensivo(double posx_,double posy_,short r_);

    void stop();
};

#endif // CANONOFENSIVO_H
