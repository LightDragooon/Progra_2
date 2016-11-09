#ifndef VENTANAARBOLVIDA_H
#define VENTANAARBOLVIDA_H

#include <QDialog>
#include "estructuras.h"

namespace Ui {
class VentanaArbolVida;
}

class VentanaArbolVida : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaArbolVida(QWidget *parent = 0);
    ~VentanaArbolVida();

    void cargarArbolVida(arbolAVL *arbolVida);
private:
    Ui::VentanaArbolVida *ui;
    void cargarLista(node *raiz);
};

#endif // VENTANAARBOLVIDA_H
