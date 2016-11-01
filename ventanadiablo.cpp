#include "ventanadiablo.h"
#include "ui_ventanadiablo.h"

VentanaDiablo::VentanaDiablo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaDiablo)
{
    ui->setupUi(this);

}

VentanaDiablo::~VentanaDiablo()
{
    delete ui;
}
