#include "ventanaarbolpersonasavl.h"
#include "ui_ventanaarbolpersonasavl.h"

VentanaArbolPersonasAVL::VentanaArbolPersonasAVL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaArbolPersonasAVL)
{
    ui->setupUi(this);
}

VentanaArbolPersonasAVL::~VentanaArbolPersonasAVL()
{
    delete ui;
}


void VentanaArbolPersonasAVL::setArbolAVL(ArbolPersonasAVL* _arbol)
{
    if (_arbol == nullptr)
        arbol = new ArbolPersonasAVL();
    else
        arbol = _arbol;
}

void VentanaArbolPersonasAVL::crearArbol()
{
    qDebug()<<"Insertando AVL";
    if (arbol->raiz != nullptr){
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,QString::number(arbol->raiz->key));
        insertarNodos(item,arbol->raiz);
    }

}

void VentanaArbolPersonasAVL::insertarNodos(QTreeWidgetItem* parent,NodoPersonaAVL* raiz)
{
    if (raiz != nullptr){
        QTreeWidgetItem* tmpDer = insertarNodoDerecha(parent, raiz);
        QTreeWidgetItem* tmpIzq = insertarNodoIzquierda(parent, raiz);
        insertarNodos(tmpDer, raiz->right);
        insertarNodos(tmpIzq, raiz->left);
    }

}

QTreeWidgetItem *VentanaArbolPersonasAVL::insertarNodoDerecha(QTreeWidgetItem *parent, NodoPersonaAVL *raiz)
{
    if(raiz != nullptr){
        if(raiz->right != nullptr){
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0,"Derecho: " + QString::number(raiz->right->key));
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

QTreeWidgetItem *VentanaArbolPersonasAVL::insertarNodoIzquierda(QTreeWidgetItem *parent, NodoPersonaAVL *raiz)
{
    if(raiz != nullptr){
        if(raiz->left != nullptr){
            QTreeWidgetItem* item = new QTreeWidgetItem();
            item->setText(0,"Izquierdo: " + QString::number(raiz->left->key));
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






void VentanaArbolPersonasAVL::on_pushButton_clicked()
{
    if (arbol != nullptr){
        if (arbol->raiz != nullptr){
            crearArbol();
        }
    }
}
