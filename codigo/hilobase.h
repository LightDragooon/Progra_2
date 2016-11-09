#ifndef HILOBASE_H
#define HILOBASE_H
#include <QtCore>
#include <QThread>
#include <QDebug>
class HiloBase : public QThread
{

public:
    HiloBase();
    bool activo;
    bool pausado;

    void pausar();
    void play();
    void activar();
    void desactivar();

};

#endif // HILOBASE_H
