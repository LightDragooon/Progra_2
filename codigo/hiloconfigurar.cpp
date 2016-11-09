#include "hiloconfigurar.h"

HiloConfigurar::HiloConfigurar(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo)
{
   ventanaPintar = _ventanaPintar;
   elMundo = _elMundo;

}

void HiloConfigurar::run(){
    QMutex mutex;
    int idSiguiente = 10000;//Ya se insertaron 10 mil personas
    while (activo){
        if(elMundo->planetaTierra->largo() != 0 && ventanaPintar->listaPersonasPlaneta == nullptr){
            mutex.lock();
            ventanaPintar->listaPersonasPlaneta = elMundo->planetaTierra;
            mutex.unlock();
            qDebug()<<"Las diez mil personas ya se han colocado en la ventana";
        }
        if(ventanaPintar->nuevosNacimientos){

            mutex.lock();
            idSiguiente = elMundo->planetaTierra->insertarPersonaCantidad(idSiguiente,ventanaPintar->cantidadNacimientos);
            mutex.unlock();

            mutex.lock();
            elMundo->planetaTierra->agregarHijos();
            mutex.unlock();

            mutex.lock();
            ventanaPintar->listaPersonasPlaneta = elMundo->planetaTierra;
            mutex.unlock();


            mutex.lock();
            ventanaPintar->nuevosNacimientos = false;
            ventanaPintar->cantidadNacimientos = 0;
            mutex.unlock();


        }
        if(ventanaPintar->generarPecados){

            mutex.lock();
            elMundo->planetaTierra->generarPecados();
            mutex.unlock();

            mutex.lock();
            ventanaPintar->listaPersonasPlaneta = elMundo->planetaTierra;
            mutex.unlock();

            sleep(1);
            mutex.lock();
            ventanaPintar->generarPecados = false;
            mutex.unlock();


        }

        if(ventanaPintar->listaPersonasPlaneta != nullptr && ventanaPintar->listaPersonasPlaneta->largo() != elMundo->planetaTierra->largo() && elMundo->planetaTierra->largo() != 0){
            mutex.lock();
            ventanaPintar->listaPersonasPlaneta = elMundo->planetaTierra;
            mutex.unlock();
            qDebug()<<"Configurando lista de personas";

        }


        mutex.lock();
        ventanaPintar->arbolVida = elMundo->arbolVida;//Actualizo el arbol de la vida en la ventana
        mutex.unlock();




        msleep(350);//Bien rapido
    }
}
