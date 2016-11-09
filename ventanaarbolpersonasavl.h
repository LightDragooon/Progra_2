#ifndef VENTANAARBOLPERSONASAVL_H
#define VENTANAARBOLPERSONASAVL_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include "estructuras.h"

namespace Ui {
class VentanaArbolPersonasAVL;
}

class VentanaArbolPersonasAVL : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaArbolPersonasAVL(QWidget *parent = 0);
    ~VentanaArbolPersonasAVL();

    void setArbolAVL(ArbolPersonasAVL *_arbol);
private slots:
    void on_pushButton_clicked();


private:
    Ui::VentanaArbolPersonasAVL *ui;
    ArbolPersonasAVL* arbol;
    void crearArbol();
    void insertarNodos(QTreeWidgetItem* parent, NodoPersonaAVL* raiz);
    QTreeWidgetItem* insertarNodoDerecha(QTreeWidgetItem *parent, NodoPersonaAVL *raiz);
    QTreeWidgetItem* insertarNodoIzquierda(QTreeWidgetItem *parent, NodoPersonaAVL *raiz);
};

#endif // VENTANAARBOLPERSONASAVL_H
