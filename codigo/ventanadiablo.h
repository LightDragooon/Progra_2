#ifndef VENTANADIABLO_H
#define VENTANADIABLO_H

#include <QDialog>

namespace Ui {
class VentanaDiablo;
}

class VentanaDiablo : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaDiablo(QWidget *parent = 0);
    ~VentanaDiablo();

private:
    Ui::VentanaDiablo *ui;
};

#endif // VENTANADIABLO_H
