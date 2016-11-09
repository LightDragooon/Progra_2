#ifndef EL_MUNDO_H
#define EL_MUNDO_H
#include "estructuras.h"
/**
 * El mundo se refiere al cielo, el infierno y el planeta tierra
 * @brief The mundo struct
 */
struct Mundo {
    ListaPersonas* planetaTierra;//Los humanos y su información
    ArbolPersonasAVL* paraisoMundo;
    arbolAVL* arbolVida;
    arbolAVL* arbolMundo;
    Mundo(){

        planetaTierra = new ListaPersonas();
        arbolMundo = new arbolAVL();
        paraisoMundo = new ArbolPersonasAVL();
        arbolVida = new arbolAVL();


    }

};

#endif // EL_MUNDO_H
