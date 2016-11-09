#include "ventanapecados.h"
#include "ui_ventanapecados.h"

VentanaPecados::VentanaPecados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaPecados)
{
    ui->setupUi(this);
}

VentanaPecados::~VentanaPecados()
{
    delete ui;
}
