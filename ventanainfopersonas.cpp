#include "ventanainfopersonas.h"
#include "ui_ventanainfopersonas.h"

VentanaInfoPersonas::VentanaInfoPersonas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaInfoPersonas)
{
    ui->setupUi(this);
}

VentanaInfoPersonas::~VentanaInfoPersonas()
{
    delete ui;
}
