#ifndef VENTANAARBOLINFIERNO_H
#define VENTANAARBOLINFIERNO_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include "estructuras.h"

namespace Ui {
class VentanaArbolInfierno;
}

class VentanaArbolInfierno : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaArbolInfierno(QWidget *parent = 0);
    ~VentanaArbolInfierno();

    void setArbolInfierno(arbolAVL *_arbol);
private slots:
    void on_pushButton_clicked();
private:
    arbolAVL *arbol;
    Ui::VentanaArbolInfierno *ui;
    void crearArbol();
    void insertarNodos(QTreeWidgetItem *parent, node *raiz);
    QTreeWidgetItem *insertarNodoDerecha(QTreeWidgetItem *parent, node *raiz);
    QTreeWidgetItem *insertarNodoIzquierda(QTreeWidgetItem *parent, node *raiz);
};

#endif // VENTANAARBOLINFIERNO_H
