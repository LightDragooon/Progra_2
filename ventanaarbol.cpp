#include "ventanaarbol.h"
#include "ui_ventanaarbol.h"
VentanaArbol::VentanaArbol(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaArbol)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(1);
}

VentanaArbol::~VentanaArbol()
{
    delete ui;
}


void VentanaArbol::setArbolPersonas(ArbolPersonas *_arbol)
{
    arbol = _arbol;
}

void VentanaArbol::crearArbol()
{
    if (arbol->raiz != nullptr){
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,arbol->raiz->persona->apellido);
        insertarNodos(item,arbol->raiz);
    }

}

void VentanaArbol::insertarNodos(QTreeWidgetItem* parent,NodoArbolPersonas* raiz)
{
    if (raiz != nullptr){
        QTreeWidgetItem* tmpDer = insertarNodoDerecha(parent, raiz);
        QTreeWidgetItem* tmpIzq = insertarNodoIzquierda(parent, raiz);
        insertarNodos(tmpDer, raiz->hijoDerecho);
        insertarNodos(tmpIzq, raiz->hijoIzquierdo);
    }

}

QTreeWidgetItem *VentanaArbol::insertarNodoDerecha(QTreeWidgetItem *parent, NodoArbolPersonas *raiz)
{
    if(raiz != nullptr){
        if(raiz->hijoDerecho != nullptr){
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0,"Derecho: " + raiz->hijoDerecho->persona->apellido);
            parent->addChild(item);
            return item;
        }
        else{
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0,"Derecho: NULL");
            parent->addChild(item);
            return nullptr;
        }
    }
    return nullptr;
}

QTreeWidgetItem *VentanaArbol::insertarNodoIzquierda(QTreeWidgetItem *parent, NodoArbolPersonas *raiz)
{
    if(raiz != nullptr){
        if(raiz->hijoIzquierdo != nullptr){
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0,"Izquierdo: " + raiz->hijoIzquierdo->persona->apellido);
            parent->addChild(item);
            return item;
        }
        else{
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0,"Izquierdo: NULL");
            parent->addChild(item);
            return nullptr;
        }
    }
    return nullptr;
}



void VentanaArbol::on_pushButton_clicked()
{
    crearArbol();
}
