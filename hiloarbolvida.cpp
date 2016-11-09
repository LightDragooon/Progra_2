#include "hiloarbolvida.h"

HiloArbolVida::HiloArbolVida(VentanaPrincipal* _ventanaPintar, Mundo* _elMundo)
{
   ventanaPintar = _ventanaPintar;
   elMundo = _elMundo;

}

void HiloArbolVida::run(){
    QMutex mutex;
    int tiempoSalvacion = 10;
    setListaRandoms();
    int idSiguiente = 0;
    while (activo){


        sleep(tiempoSalvacion);

        //Se va a salvar a una persona
        mutex.lock();
        elMundo->arbolVida->raiz = elMundo->arbolVida->insertar(randomsUnicos[idSiguiente++]);
        mutex.unlock();
        //Después de haber insertado una persona debo actualizar la  ventana
       //mutex.lock();
        //ventanaPintar->arbolVida = elMundo->arbolVida;
       //mutex.unlock();
        qDebug()<<"Se ha salvado una persona";

    }

}

void HiloArbolVida::setListaRandoms(){
    //Inicializo el array
    for(int i = 0; i < 10000000; i++)
        randomsUnicos[i] = i;
    //Le hago un shuffle al array

    //GENERADOR PARA MIL 1
    std::mt19937 randomizador (time(NULL));

    int temp;
    for (int i = 9999999; i >= 0; i--){
        std::uniform_real_distribution<double> distRandomizador(0.0, i);
        int random = distRandomizador(randomizador);
        temp = randomsUnicos[i];
        randomsUnicos[i] = randomsUnicos[random];
        randomsUnicos[random] = temp;

    }
}
