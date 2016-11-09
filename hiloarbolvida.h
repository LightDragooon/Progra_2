#ifndef HILOARBOLVIDA_H
#define HILOARBOLVIDA_H

#include "hilobase.h"
#include "el_mundo.h"
#include "ventanaprincipal.h"

class HiloArbolVida : public HiloBase
{
public:
    unsigned int randomsUnicos [9999999];
    VentanaPrincipal* ventanaPintar;
    Mundo* elMundo;

    HiloArbolVida(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo);
    void run();
private:
    void setListaRandoms();
};

#endif // HILOARBOLVIDA_H
