#ifndef EL_MUNDO_H
#define EL_MUNDO_H
#include "estructuras.h"
/**
 * El mundo se refiere al cielo, el infierno y el planeta tierra
 * @brief The mundo struct
 */
struct Mundo {
    ListaPersonas* planetaTierra;//Los humanos y su información
    Mundo(){

        planetaTierra = new ListaPersonas();
    }

};

#endif // EL_MUNDO_H
