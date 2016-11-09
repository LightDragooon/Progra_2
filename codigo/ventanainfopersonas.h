#ifndef VENTANAINFOPERSONAS_H
#define VENTANAINFOPERSONAS_H

#include <QDialog>
#include "estructuras.h"

namespace Ui {
class VentanaInfoPersonas;
}

class VentanaInfoPersonas : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaInfoPersonas(QWidget *parent = 0);
    ~VentanaInfoPersonas();


    void setListaPersonas(ListaPersonas* _listaPersonasT);

private:
    Ui::VentanaInfoPersonas *ui;
    ListaPersonas* listaPersonasT;
};

#endif // VENTANAINFOPERSONAS_H
