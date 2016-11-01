#ifndef VENTANANACIMIENTO_H
#define VENTANANACIMIENTO_H

#include <QDialog>

namespace Ui {
class VentanaNacimiento;
}

class VentanaNacimiento : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaNacimiento(QWidget *parent = 0);
    ~VentanaNacimiento();

    int numNacimientos () const;

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::VentanaNacimiento *ui;
};

#endif // VENTANANACIMIENTO_H
