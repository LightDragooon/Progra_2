#ifndef VENTANAARBOLAVL_H
#define VENTANAARBOLAVL_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include "estructuras.h"

namespace Ui {
class VentanaArbolAVL;
}

class VentanaArbolAVL : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaArbolAVL(QWidget *parent = 0);
    ~VentanaArbolAVL();

    void setArbolAVL(arbolAVL *_arbol);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    arbolAVL *arbol;
    Ui::VentanaArbolAVL *ui;
    void crearArbol();
    void insertarNodos(QTreeWidgetItem *parent, node *raiz);
    QTreeWidgetItem *insertarNodoDerecha(QTreeWidgetItem *parent, node *raiz);
    QTreeWidgetItem *insertarNodoIzquierda(QTreeWidgetItem *parent, node *raiz);
};

#endif // VENTANAARBOLAVL_H
