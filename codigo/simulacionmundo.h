#ifndef SIMULACIONMUNDO_H
#define SIMULACIONMUNDO_H
#include "ventanaprincipal.h"
#include "el_mundo.h"
#include "hiloconfigurar.h"
#include "hiloarbolvida.h"

struct Simulacion{
    VentanaPrincipal* ventanaRef;
    Mundo* mundoRef;

    HiloConfigurar* configurar;
    HiloArbolVida* configVida;

    Simulacion(){
        mundoRef = new Mundo();
        mundoRef->planetaTierra->insertarPersonaCantidad(0, 10000);

        mundoRef->planetaTierra->agregarHijos();
        ventanaRef = new VentanaPrincipal();
        configurar = new HiloConfigurar(ventanaRef,mundoRef);
        configurar->start();
        configVida = new HiloArbolVida(ventanaRef,mundoRef);
        configVida->start();

    }
};
#endif // SIMULACIONMUNDO_H
