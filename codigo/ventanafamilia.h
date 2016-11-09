#ifndef VENTANAFAMILIA_H
#define VENTANAFAMILIA_H

#include <QDialog>
#include "estructuras.h"

namespace Ui {
class VentanaFamilia;
}

class VentanaFamilia : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaFamilia(QWidget *parent = 0);
    ~VentanaFamilia();

    void setListaPersonas(NodoPersona *nodoAbuelo);
private:
    Ui::VentanaFamilia *ui;
};

#endif // VENTANAFAMILIA_H
