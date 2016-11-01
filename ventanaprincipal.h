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

    ListaPersonas* listaPersonasPlaneta = nullptr;

    bool nuevosNacimientos = false;
    int cantidadNacimientos = 0;

    bool generarPecados = false;

private slots:
    void on_verInfoPersonas_clicked();



    void on_generarNacimientos_clicked();
    void on_generarPecados_clicked();
    void on_action_rbol_Apellidos_triggered();
};

#endif // VENTANAPRINCIPAL_H
