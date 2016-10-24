#include "hilopintar.h"

HiloPintar::HiloPintar(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo)
{
   ventanaPintar = _ventanaPintar;
   elMundo = _elMundo;

}

void HiloPintar::run(){
    QMutex mutex;

    while (activo){

        msleep(200);//Bien rapido
    }
}
