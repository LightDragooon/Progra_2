#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>
#include "estructuras.h"

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

    Ui::VentanaPrincipal *ui;

    ListaPersonas* listaPersonasPlaneta = new ListaPersonas();

private slots:
    void on_verInfoPersonas_clicked();



};

#endif // VENTANAPRINCIPAL_H
