#ifndef VENTANAARBOL_H
#define VENTANAARBOL_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include "estructuras.h"

namespace Ui {
class VentanaArbol;
}

class VentanaArbol : public QDialog
{
    Q_OBJECT

void crearArbol ();
void insertarNodos(QTreeWidgetItem *parent, NodoArbolPersonas* raiz);
QTreeWidgetItem* insertarNodoDerecha(QTreeWidgetItem* parent, NodoArbolPersonas* raiz);
QTreeWidgetItem* insertarNodoIzquierda(QTreeWidgetItem* parent, NodoArbolPersonas* raiz);
public:
    explicit VentanaArbol(QWidget *parent = 0);
    ~VentanaArbol();

    ArbolPersonas* arbol;
    void setArbolPersonas (ArbolPersonas* _arbol);

private slots:
    void on_pushButton_clicked();

private:
    Ui::VentanaArbol *ui;
};

#endif // VENTANAARBOL_H
