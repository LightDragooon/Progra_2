#ifndef HILOCONFIGURAR_H
#define HILOCONFIGURAR_H

#include "hilobase.h"
#include "el_mundo.h"
#include "ventanaprincipal.h"

class HiloConfigurar : public HiloBase
{
public:

    VentanaPrincipal* ventanaPintar;
    Mundo* elMundo;

    HiloConfigurar(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo);
    void run();
};

#endif // HILOCONFIGURAR_H
