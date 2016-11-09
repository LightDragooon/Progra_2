#ifndef VENTANATOP10_H
#define VENTANATOP10_H

#include <QDialog>
#include "estructuras.h"

namespace Ui {
class VentanaTop10;
}

class VentanaTop10 : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaTop10(QWidget *parent = 0);
    ~VentanaTop10();

    void setTop10(QString top10[10], int pecados[]);
    void setBandera (QString top10[]);

private:
    Ui::VentanaTop10 *ui;

};

#endif // VENTANATOP10_H
