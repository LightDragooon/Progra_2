#include "ventanaarbolvida.h"
#include "ui_ventanaarbolvida.h"

VentanaArbolVida::VentanaArbolVida(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaArbolVida)
{
    ui->setupUi(this);
}

VentanaArbolVida::~VentanaArbolVida()
{
    delete ui;
}

void VentanaArbolVida::cargarArbolVida(arbolAVL* arbolVida){

    if(arbolVida != nullptr)
        cargarLista (arbolVida->raiz);
}

void VentanaArbolVida::cargarLista(node* raiz){

    if(raiz != nullptr){
        ui->listWidget->addItem("+ " + QString::number(raiz->key));
        cargarLista(raiz->left);
        cargarLista(raiz->right);
    }


}
