#include "ventanaprincipal.h"
#include <QApplication>
#include "simulacionmundo.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Simulacion* simulacionNueva = new Simulacion();
    simulacionNueva->ventanaRef->show();

    return a.exec();
}
