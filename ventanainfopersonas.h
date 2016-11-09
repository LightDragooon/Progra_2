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

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::VentanaInfoPersonas *ui;
    ListaPersonas* listaPersonasT;
    void setComboBoxes();
    void filtrarLista(QString filter, int columna);
};

#endif // VENTANAINFOPERSONAS_H
