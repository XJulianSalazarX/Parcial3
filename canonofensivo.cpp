#include "canonofensivo.h"

CanonOfensivo::CanonOfensivo(double posx_, double posy_, short r_)
             :Canon(posx_,posy_,r_)
{

}

void CanonOfensivo::stop()
{
    portal->stopBala();
}
