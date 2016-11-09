#include "ventanaid.h"
#include "ui_ventanaid.h"
#include <QDebug>

VentanaID::VentanaID(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaID)
{
    ui->setupUi(this);


}

VentanaID::~VentanaID()
{
    delete ui;
}

void VentanaID::on_buttonBox_accepted()
{
    accept();
}

void VentanaID::on_buttonBox_rejected()
{
    reject();
}

int VentanaID::obtenerID() const
{
    return ui->spinBox->value();
}

void VentanaID::setIDs(int _listaId[], int tamanno, int _cantidadHijos[])
{
    for (int i = 0; i < tamanno; i++){
        ui->listWidget->addItem(QString::number(i+1) +") "+ QString::number(_listaId[i]) + " tiene " + QString::number(_cantidadHijos[i]) + " hijos");
    }
}
