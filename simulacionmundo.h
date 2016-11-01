#ifndef SIMULACIONMUNDO_H
#define SIMULACIONMUNDO_H
#include "ventanaprincipal.h"
#include "el_mundo.h"
#include "hiloconfigurar.h"
#include "hilopintar.h"

struct Simulacion{
    VentanaPrincipal* ventanaRef;
    Mundo* mundoRef;

    HiloConfigurar* configurar;
    HiloPintar* pintar;

    int idSiguiente;

    Simulacion(){
        idSiguiente = 0;
        mundoRef = new Mundo();
        mundoRef->planetaTierra->insertarPersonaCantidad(0, 10000);
        mundoRef->planetaTierra->agregarHijos();
        ventanaRef = new VentanaPrincipal();
        configurar = new HiloConfigurar(ventanaRef,mundoRef);
        configurar->start();
        pintar = new HiloPintar(ventanaRef,mundoRef);
        pintar->start();

    }
};
#endif // SIMULACIONMUNDO_H
