#include "hiloconfigurar.h"

HiloConfigurar::HiloConfigurar(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo)
{
   ventanaPintar = _ventanaPintar;
   elMundo = _elMundo;

}

void HiloConfigurar::run(){
    QMutex mutex;
    while (activo){
        if(ventanaPintar->listaPersonasPlaneta->largo() != elMundo->planetaTierra->largo() && elMundo->planetaTierra->largo() != 0){
            mutex.lock();
            ventanaPintar->listaPersonasPlaneta = elMundo->planetaTierra;
            mutex.unlock();
            qDebug()<<"entro";
        }
        msleep(200);//Bien rapido
    }
}
