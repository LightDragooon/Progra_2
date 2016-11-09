#include "hiloarbolvida.h"



HiloArbolVida::HiloArbolVida(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo)
{
   ventanaPintar = _ventanaPintar;
   elMundo = _elMundo;

}

void HiloArbolVida::run(){
    QMutex mutex;
    int tiempoSalvacion = 10;
    //EL RANDOM GENERARÁ LOS ID's DE LAS PERSONAS QUE SE SALVAN Y VAN AL CIELO
    //GENERADOR
    std::mt19937 salvador (time(NULL));
    //Distribución 1000
    std::uniform_real_distribution<double> distribucion(0.0, 9999999.0);//ID's
    while (activo){
        if(ventanaPintar->configArbolVida){

            mutex.lock();
            tiempoSalvacion = ventanaPintar->tiempoSalvacion;
            mutex.unlock();

            mutex.lock();
            ventanaPintar->configArbolVida = false;
            mutex.unlock();
        }
        sleep(tiempoSalvacion);//Tiempo que espera el arbol de la vida antes de enviar al cielo a alguien


        //Después de esperar lo indicado, el va a agregar una persona al arbol de la vida
        elMundo->arbolVida->insertar(distribucion(salvador));



    }
}
