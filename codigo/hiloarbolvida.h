#ifndef HILOARBOLVIDA_H
#define HILOARBOLVIDA_H

#include "hilobase.h"
#include "el_mundo.h"
#include "ventanaprincipal.h"

class HiloArbolVida : public HiloBase
{
public:
    VentanaPrincipal* ventanaPintar;
    Mundo* elMundo;
    HiloArbolVida(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo);
    void run();
};

#endif // HILOARBOLVIDA_H
