#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "ventanainfopersonas.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_verInfoPersonas_clicked()
{
    if(listaPersonasPlaneta != nullptr){
        VentanaInfoPersonas verInfoPersonas(this);
        verInfoPersonas.exec();

    }
}
