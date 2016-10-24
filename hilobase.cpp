#include "hilobase.h"


HiloBase::HiloBase(){
    pausado = false;
    activo = true;
}
void HiloBase::pausar(){
    pausado = true;
}

void HiloBase::play(){
    pausado = false;
}

void HiloBase::activar(){
    activo = true;
}

void HiloBase::desactivar(){
        activo = false;
}
