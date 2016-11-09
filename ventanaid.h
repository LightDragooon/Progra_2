#ifndef VENTANAID_H
#define VENTANAID_H

#include <QDialog>

namespace Ui {
class VentanaID;
}

class VentanaID : public QDialog
{
    Q_OBJECT

public:
    explicit VentanaID(QWidget *parent = 0);
    ~VentanaID();
    int obtenerID() const;
    void setIDs(int _listaId[], int tamanno, int _cantidadHijos[]);
private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::VentanaID *ui;
    int listaId[];
};

#endif // VENTANAID_H
