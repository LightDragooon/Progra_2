#include "ventanaarbolavl.h"
#include "ui_ventanaarbolavl.h"

VentanaArbolAVL::VentanaArbolAVL(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaArbolAVL)
{
    ui->setupUi(this);
}

VentanaArbolAVL::~VentanaArbolAVL()
{
    delete ui;
}
void VentanaArbolAVL::setArbolAVL(arbolAVL *_arbol)
{
    if (_arbol == nullptr)
        arbol = new arbolAVL();
    else
        arbol = _arbol;
}

void VentanaArbolAVL::crearArbol()
{
    qDebug()<<"Insertando AVL";
    if (arbol->raiz != nullptr){
        QTreeWidgetItem* item = new QTreeWidgetItem(ui->treeWidget);
        item->setText(0,QString::number(arbol->raiz->key));
        insertarNodos(item,arbol->raiz);
    }

}

void VentanaArbolAVL::insertarNodos(QTreeWidgetItem* parent,node* raiz)
{
    if (raiz != nullptr){
        QTreeWidgetItem* tmpDer = insertarNodoDerecha(parent, raiz);
        QTreeWidgetItem* tmpIzq = insertarNodoIzquierda(parent, raiz);
        insertarNodos(tmpDer, raiz->right);
        insertarNodos(tmpIzq, raiz->left);
    }

}

QTreeWidgetItem *VentanaArbolAVL::insertarNodoDerecha(QTreeWidgetItem *parent, node *raiz)
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

QTreeWidgetItem *VentanaArbolAVL::insertarNodoIzquierda(QTreeWidgetItem *parent, node *raiz)
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



void VentanaArbolAVL::on_pushButton_clicked()
{
    if (arbol != nullptr){
        if (arbol->raiz != nullptr){
            crearArbol();
        }
    }

}
void VentanaArbolAVL::on_pushButton_2_clicked()//AGREGAR
{
    arbol->raiz = arbol->insertar(ui->spinBox->value());
}

void VentanaArbolAVL::on_pushButton_3_clicked()//ELIMINAR
{
    arbol->raiz = arbol->remover(ui->spinBox->value());
}
