#ifndef HILOPINTAR_H
#define HILOPINTAR_H

#include "hilobase.h"
#include "el_mundo.h"
#include "ventanaprincipal.h"

class HiloPintar : public HiloBase
{
public:
    VentanaPrincipal* ventanaPintar;
    Mundo* elMundo;

    HiloPintar(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo);
    void run();


};

#endif // HILOPINTAR_H
