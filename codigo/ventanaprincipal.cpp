#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include "ventanainfopersonas.h"
#include "ventananacimiento.h"
#include "ventanadiablo.h"
#include "ventanaarbol.h"
#include "ventanatop10.h"
#include "ventanatop5.h"
#include "ventanaid.h"
#include "ventanafamilia.h"
#include "ventanaarbolinfierno.h"
#include "ventanaarbolavl.h"
#include "ventanaarbolvida.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    /*
    QMovie* mundoSpins = new QMovie("C:/Users/Esteban/Desktop/Video Mundo/2min.gif");
    if(mundoSpins->isValid()){
        QMovie::CacheAll;
        ui->mundoGira->setMovie(mundoSpins);
        mundoSpins->start();

    }
    */
    QMovie* mundoSpins = new QMovie(":/recursos/videos/mundoCrop.gif");
    if(mundoSpins->isValid()){
        ui->mundoGira->setMovie(mundoSpins);
        mundoSpins->start();

    }

}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_verInfoPersonas_clicked()
{
    if(listaPersonasPlaneta != nullptr){

        desplegarLista(listaPersonasPlaneta);
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

void VentanaPrincipal::on_actionTop_10_m_s_pecadores_triggered()
{
    //Top 10 de los países más pecadores
    if(listaPersonasPlaneta != nullptr){
        int cantidadPecadosPaises[100];//Son 100 países y  corresponde al array nombrePaises
        //Inicializo en 0
        for (int i = 0; i < 100 ; i++){
            cantidadPecadosPaises[i] = 0;//Quiero el nombre del país
        }
        int maxTmp;
        QString nombrePaises [100];
        //Cargo con los nombres
        for (int i = 0; i < 100 ; i++){
            nombrePaises[i] = listaPersonasPlaneta->infoPersona->listaPaises[i][0];//Quiero el nombre del país
        }
        QString nombre10paises[10];
        int cantidad10paises[10];
        NodoPersona* personaActual;
        //Lo primero es poder sumar los pecados a los países correspondientes
        for(int i = 0; i < listaPersonasPlaneta->largo();i++){
            personaActual = listaPersonasPlaneta->buscarPersonaPos(i);//Obtengo la persona
            for (int j = 0; j < 100; j++){
                //Busco a que país pertenece
                if(personaActual->pais == nombrePaises[j]){//Enontré el país
                    //Debo sumar todos los pecados de la persona
                    for(int k = 0; k < 7; k++){
                        cantidadPecadosPaises[j] += personaActual->pecados[k];//Sumo los pecados
                    }
                    break;
                }
            }
            //Después de sumar paso a la siguiente persona
        }
        //Ya he sumado los pecados a los países

        //Debo buscar al top 10
        for (int i = 0; i < 10; i++){
            maxTmp = 0;
            for (int j = 0; j < 100; j++){
                if(cantidadPecadosPaises[j] > maxTmp)
                    maxTmp = cantidadPecadosPaises[j];//Nuevo máximo
            }

            //Al salir de acá ya encontré el máximo
            for (int j = 0; j < 100; j++){
                if(cantidadPecadosPaises[j] == maxTmp){
                    //Significa que tengo al maximo y la posición indicada
                    nombre10paises[i] = nombrePaises[j];
                    cantidad10paises[i] = cantidadPecadosPaises[j];
                    cantidadPecadosPaises[j] = 0;//Ya utilice este país
                    break;//YA NO OCUPO SEGUIR ANALIZANDO >:|
                }
            }
        }

        VentanaTop10 verTop10(this);
        qDebug()<<"Ventana top10";
        verTop10.setBandera(nombre10paises);
        verTop10.setTop10(nombre10paises, cantidad10paises);
        verTop10.exec();

    }


}

void VentanaPrincipal::on_actionTop_5_pa_ses_menos_pecadores_triggered()
{
    //Top 5 de los países menos pecadores
    if(listaPersonasPlaneta != nullptr){
        int cantidadPecadosPaises[100];//Son 100 países y  corresponde al array nombrePaises
        //Inicializo en 0
        for (int i = 0; i < 100 ; i++){
            cantidadPecadosPaises[i] = 0;//Quiero el nombre del país
        }
        int minTmp;
        QString nombrePaises [100];
        //Cargo con los nombres
        for (int i = 0; i < 100 ; i++){
            nombrePaises[i] = listaPersonasPlaneta->infoPersona->listaPaises[i][0];//Quiero el nombre del país
        }
        QString nombre5paises[5];
        int cantidad5paises[5];
        NodoPersona* personaActual;
        //Lo primero es poder sumar los pecados a los países correspondientes
        for(int i = 0; i < listaPersonasPlaneta->largo();i++){
            personaActual = listaPersonasPlaneta->buscarPersonaPos(i);//Obtengo la persona
            for (int j = 0; j < 100; j++){
                //Busco a que país pertenece
                if(personaActual->pais == nombrePaises[j]){//Enontré el país
                    //Debo sumar todos los pecados de la persona
                    for(int k = 0; k < 7; k++){
                        cantidadPecadosPaises[j] += personaActual->pecados[k];//Sumo los pecados
                    }
                    break;
                }
            }
            //Después de sumar paso a la siguiente persona
        }
        //Ya he sumado los pecados a los países

        //Debo buscar al top 5 de menos pecadores
        for (int i = 0; i < 5; i++){
            minTmp = std::numeric_limits<int>::max();//Le asigno el maximo valor posible
            for (int j = 0; j < 100; j++){
                if(cantidadPecadosPaises[j] < minTmp)
                    minTmp = cantidadPecadosPaises[j];//Nuevo mínimo
            }

            //Al salir de acá ya encontré el mínimo
            for (int j = 0; j < 100; j++){
                if(cantidadPecadosPaises[j] == minTmp){
                    //Significa que tengo al mínimo y la posición indicada
                    nombre5paises[i] = nombrePaises[j];
                    cantidad5paises[i] = cantidadPecadosPaises[j];
                    cantidadPecadosPaises[j] = std::numeric_limits<int>::max();//Ya utilice este país, entonces le asigno el máximo
                    break;//YA NO OCUPO SEGUIR ANALIZANDO >:|
                }
            }
        }

        VentanaTop5 verTop5(this);
        qDebug()<<"Ventana top5";
        verTop5.setBandera(nombre5paises);
        verTop5.setTop5(nombre5paises, cantidad5paises);
        verTop5.exec();

    }
}



/**
 * @brief VentanaPrincipal::desplegarLista
 * @param listaDesplegar
 * Según la lista que recibe, la muestra en pantalla
 */
void VentanaPrincipal::desplegarLista(ListaPersonas* listaDesplegar)
{
    if(listaDesplegar != nullptr){

        VentanaInfoPersonas verInfoPersonas(this);
        qDebug()<<"cree la ventana";
        verInfoPersonas.setListaPersonas(listaDesplegar);
        verInfoPersonas.exec();

    }
}


void VentanaPrincipal::on_actionPecados_Familiares_ID_triggered()
{
    //PECADOS FAMILIARES A TRAVES DE UN ID

    int arregloID[listaPersonasPlaneta->largo()];
    int arregloCantHijos[listaPersonasPlaneta->largo()];
    NodoPersona* personaActual;
    int cantHijos;
    for (int i = 0; i < listaPersonasPlaneta->largo(); i++){
        personaActual = listaPersonasPlaneta->buscarPersonaPos(i);
        arregloID[i] = personaActual->id;
        cantHijos = 0;
        for(int j = 0; j < 8; j++){
            if(personaActual->listaHijos[j] != nullptr)
                cantHijos++;
        }
        arregloCantHijos[i] = cantHijos;
    }
    //Primero se solicita el ID
    int respuesta;
    VentanaID ventID (this);
    ventID.setIDs(arregloID,listaPersonasPlaneta->largo(),arregloCantHijos);
    respuesta = ventID.exec();
    if (respuesta == QDialog::Rejected)
        return;

    //Si estoy acá ya tengo el id;
    NodoPersona* abuelo = listaPersonasPlaneta->buscarPersonaID(ventID.obtenerID());
    if (abuelo != nullptr){
        VentanaFamilia ventF (this);
        ventF.setListaPersonas(abuelo);
        ventF.exec();
    }
}

void VentanaPrincipal::on_actionArbol_AVL_triggered()
{


    VentanaArbolAVL ventArbolAVL (this);
    ventArbolAVL.setArbolAVL(nullptr);
    ventArbolAVL.exec();
}

void VentanaPrincipal::on_actionDestinados_a_la_salvaci_n_triggered()
{
    //Despliega a aquellos que se encuentren en el arbol de la vida
    VentanaArbolAVL ventArbolAVL (this);
    ventArbolAVL.setArbolAVL(arbolVida);
    ventArbolAVL.exec();
}

void VentanaPrincipal::on_actionDestinados_a_la_salvaci_n_lista_triggered()
{
    VentanaArbolVida ventVida (this);
    ventVida.cargarArbolVida(arbolVida);
    ventVida.exec();
}
