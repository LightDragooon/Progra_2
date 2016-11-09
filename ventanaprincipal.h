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
    arbolAVL* arbolVida = nullptr;

    bool nuevosNacimientos = false;
    int cantidadNacimientos = 0;

    bool generarPecados = false;

    bool configArbolVida = false;
    int tiempoSalvacion = 10;
private slots:
    void on_verInfoPersonas_clicked();
    void on_generarNacimientos_clicked();
    void on_generarPecados_clicked();
    void on_action_rbol_Apellidos_triggered();
    void on_actionTop_10_m_s_pecadores_triggered();
    void on_actionTop_5_pa_ses_menos_pecadores_triggered();
    void desplegarLista (ListaPersonas* listaDesplegar);
    void on_actionPecados_Familiares_ID_triggered();
    void on_actionArbol_AVL_triggered();
    void on_actionDestinados_a_la_salvaci_n_triggered();
    void on_actionDestinados_a_la_salvaci_n_lista_triggered();
    void on_actionPecados_Filtro_triggered();
    void on_action_rbol_Mundo_triggered();
};

#endif // VENTANAPRINCIPAL_H
