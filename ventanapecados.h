#ifndef VENTANAPECADOS_H
#define VENTANAPECADOS_H

#include <QDialog>

namespace Ui {
class VentanaPecados;
}

class VentanaPecados : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaPecados(QWidget *parent = 0);
    ~VentanaPecados();

private:
    Ui::VentanaPecados *ui;
};

#endif // VENTANAPECADOS_H
