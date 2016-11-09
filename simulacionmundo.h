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
    HiloArbolVida* salvacionHumanos;

    Simulacion(){
        mundoRef = new Mundo();
        mundoRef->planetaTierra->insertarPersonaCantidad(0, 1800);

        mundoRef->planetaTierra->agregarHijos();
        ventanaRef = new VentanaPrincipal();

        configurar = new HiloConfigurar(ventanaRef,mundoRef);
        configurar->start();

        salvacionHumanos = new HiloArbolVida(ventanaRef,mundoRef);
        salvacionHumanos->start();

    }
};
#endif // SIMULACIONMUNDO_H
