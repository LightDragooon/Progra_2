#include "ventananacimiento.h"
#include "ui_ventananacimiento.h"

VentanaNacimiento::VentanaNacimiento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaNacimiento)
{
    ui->setupUi(this);
}

VentanaNacimiento::~VentanaNacimiento()
{
    delete ui;
}

void VentanaNacimiento::on_buttonBox_accepted()
{
    accept();
}

void VentanaNacimiento::on_buttonBox_rejected()
{
    reject();
}

int VentanaNacimiento::numNacimientos () const{
    return ui->spinBox->value();
}
