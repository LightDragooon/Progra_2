#include "ventanaarbolinfierno.h"
#include "ui_ventanaarbolinfierno.h"

VentanaArbolInfierno::VentanaArbolInfierno(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaArbolInfierno)
{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(1);
}

VentanaArbolInfierno::~VentanaArbolInfierno()
{
    delete ui;
}


void VentanaArbolInfierno::setArbolInfierno(arbolAVL *_arbol)
{
    arbol = _arbol;
}

void VentanaArbolInfierno::crearArbol()
{
    qDebug()<<"Insertando AVL";
    if (arbol->raiz != nullptr){
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,QString::number(arbol->raiz->key));
        insertarNodos(item,arbol->raiz);
    }

}

void VentanaArbolInfierno::insertarNodos(QTreeWidgetItem* parent,node* raiz)
{
    if (raiz != nullptr){
        QTreeWidgetItem* tmpDer = insertarNodoDerecha(parent, raiz);
        QTreeWidgetItem* tmpIzq = insertarNodoIzquierda(parent, raiz);
        insertarNodos(tmpDer, raiz->right);
        insertarNodos(tmpIzq, raiz->left);
    }

}

QTreeWidgetItem *VentanaArbolInfierno::insertarNodoDerecha(QTreeWidgetItem *parent, node *raiz)
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

QTreeWidgetItem *VentanaArbolInfierno::insertarNodoIzquierda(QTreeWidgetItem *parent, node *raiz)
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



void VentanaArbolInfierno::on_pushButton_clicked()
{
    crearArbol();
}
