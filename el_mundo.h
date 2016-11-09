#ifndef EL_MUNDO_H
#define EL_MUNDO_H
#include "estructuras.h"
/**
 * El mundo se refiere al cielo, el infierno y el planeta tierra
 * @brief The mundo struct
 */
struct Mundo {
    ListaPersonas* planetaTierra;//Los humanos y su información
    Infierno * infierno;//Todos los que están en el infierno

    Mundo(){
        planetaTierra = new ListaPersonas();
        infierno = new Infierno();
    }

    /**
     * Esta función lo que hace es agarrar la lista de personas y condenarlas por país
     * Esta función llama a condenar país con todos los países definidos en la lista de países
     * @brief condenar
     * @return Tal vez haga que retorne la cantidad de condenados
     */
    int condenar(){
        int condenados = 0;
        for(int i = 0;i < 100;i++){
            QString pais = planetaTierra->infoPersona->listaPaises[i];
            condenados = condenados + condenarPais(pais);
        }
    }

    /**
     * Esta función va a condenar un país a la vez, lo que hace es que busca en
     * toda la lista todos las personas cuyo país coincida con el heap que se está formando
     * Luego de esto se sacará el 25% del heap y se enviarán al infierno
     * @brief condenarPais
     * @param paisACondenar El país que se desea condenar
     * @return Tal vez la cantidad de condenados en este país
     */
    int condenarPais(QString paisACondenar){
        int listaParaHeap[planetaTierra->largo()];
        int posicionEscrituraHeap = 0;
        for(int i = 0;i < planetaTierra->largo();i++){
            heap[i] = -1;
        }
        for(int i = 0;i < planetaTierra->largo();i++){
            NodoPersona * personaACondenar = planetaTierra->buscarPersonaPos(i);
            if(QString::compare(paisACondenar,personaACondenar->pais,Qt::CaseInsensitive)){
                listaParaHeap[posicionEscrituraHeap] = personaACondenar->id;
                posicionEscrituraHeap++;
            }
        }
        int heapLimpio[posicionEscrituraHeap+1];
        for(int i = 0;i < posicionEscrituraHeap+1;i++){
            heapLimpio[i] = listaParaHeap[i];
        }
        crearMaxHeap(heapLimpio,posicionEscrituraHeap+1);
        delete listaParaHeap;
        int cantidadCondenados = (int)(posicionEscrituraHeap+1)*0.25;
        int condenados[cantidadCondenados];
        for(int i = 0;i < cantidadCondenados;i++){
            condenados[i] = heapLimpio[i];
        }
        moverAlInfierno(condenados,cantidadCondenados);
        delete posicionEscrituraHeap;
        delete condenados;
        return cantidadCondenados;
    }

    void moverAlInfierno(int heap[],int cantidadCondenados){
        for(int i = 0;i < cantidadCondenados;i++){
            infierno->splayBusqueda->insertarNodo(planetaTierra->buscarPersonaID(heap[i]));
            planetaTierra->borrarListaID(heap[i]);
        }
    }
};

#endif // EL_MUNDO_H
