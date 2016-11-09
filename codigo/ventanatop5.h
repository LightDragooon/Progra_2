#ifndef VENTANATOP5_H
#define VENTANATOP5_H

#include <QDialog>

namespace Ui {
class VentanaTop5;
}

class VentanaTop5 : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaTop5(QWidget *parent = 0);
    ~VentanaTop5();

    void setTop5(QString top5[5], int pecados[5]);
    void setBandera (QString top5[5]);

private:
    Ui::VentanaTop5 *ui;
};

#endif // VENTANATOP5_H
