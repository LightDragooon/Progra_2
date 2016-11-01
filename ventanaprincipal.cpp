#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "ventanainfopersonas.h"
#include "ventananacimiento.h"
#include "ventanadiablo.h"
#include "ventanaarbol.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);


}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_verInfoPersonas_clicked()
{
    if(listaPersonasPlaneta != nullptr){

        VentanaInfoPersonas verInfoPersonas(this);
        qDebug()<<"cree la ventana";
        verInfoPersonas.setListaPersonas(listaPersonasPlaneta);
        verInfoPersonas.exec();

    }
}

void VentanaPrincipal::on_generarNacimientos_clicked()
{

    int respuesta;
    VentanaNacimiento ventNac (this);
    respuesta = ventNac.exec();
    if (respuesta == QDialog::Rejected)
        return;

    nuevosNacimientos = true;
    cantidadNacimientos = ventNac.numNacimientos();


}



void VentanaPrincipal::on_generarPecados_clicked()
{

    qDebug()<<"Pecados generandose";
    generarPecados = true;
    VentanaDiablo ventDiablo (this);
    ventDiablo.exec();    

}

void VentanaPrincipal::on_action_rbol_Apellidos_triggered()
{
    ArbolPersonas* arbol = new ArbolPersonas();
    NodoPersona* personaMedio = listaPersonasPlaneta->buscarPersonaPos(listaPersonasPlaneta->largo()/2);
    NodoPersona* personaActual = personaMedio;

    while (personaActual != nullptr){
        //Ciclo para agregar al arbol aquellos con igual apellido
        arbol->insertarPersona(personaActual);

        personaActual = personaActual->siguiente;
    }
    personaActual = listaPersonasPlaneta->primeraPersona;
    while (personaActual->id != personaMedio->id){
        //Ciclo para agregar al arbol aquellos con igual apellido
        arbol->insertarPersona(personaActual);

        personaActual = personaActual->siguiente;
    }
    VentanaArbol arbolApellidos (this);
    arbolApellidos.setArbolPersonas(arbol);
    arbolApellidos.exec();
}
