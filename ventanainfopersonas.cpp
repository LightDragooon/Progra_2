#include "ventanainfopersonas.h"
#include "ui_ventanainfopersonas.h"

VentanaInfoPersonas::VentanaInfoPersonas(QWidget *parent) : QDialog(parent),ui(new Ui::VentanaInfoPersonas){
    ui->setupUi(this);
    setComboBoxes();

}

VentanaInfoPersonas::~VentanaInfoPersonas()
{
    delete ui;
}

void VentanaInfoPersonas::setListaPersonas(ListaPersonas* _listaPersonasT){
    listaPersonasT = _listaPersonasT;
    NodoPersona* personaActual;
    QString hijos= "";
    int sumaPecados;
    for(int i = 0; i < listaPersonasT->largo(); i++){

        personaActual = listaPersonasT->buscarPersonaPos(i);
        //Cantidad de filas actuales
        int insertRow = ui->tablaPersonas->rowCount();

        //Agrego al final de la tabla
        ui->tablaPersonas->insertRow(insertRow);

        //Agrego los objetos en las columnas correspondientes
        ui->tablaPersonas->setItem(insertRow, 0,new QTableWidgetItem(QString::number(personaActual->id)));//ID
        ui->tablaPersonas->setItem(insertRow, 1,new QTableWidgetItem(personaActual->nombre));//NOMBRE
        ui->tablaPersonas->setItem(insertRow, 2,new QTableWidgetItem(personaActual->apellido));//APELLIDO
        ui->tablaPersonas->setItem(insertRow, 3,new QTableWidgetItem(personaActual->pais));//PAÍS
        ui->tablaPersonas->setItem(insertRow, 4,new QTableWidgetItem(personaActual->creencia));//CREENCIA
        ui->tablaPersonas->setItem(insertRow, 5,new QTableWidgetItem(personaActual->profesion));//PROFESIÓN
        ui->tablaPersonas->setItem(insertRow, 6,new QTableWidgetItem(personaActual->correo));//CORREO
        ui->tablaPersonas->setItem(insertRow, 7,new QTableWidgetItem(personaActual->fechaNacimiento));//NACIMIENTO

        if(personaActual->listaHijos[0] != nullptr){
            hijos= "";
            for (int i = 0; i < 8; i++){
                if (personaActual->listaHijos[i] != nullptr)
                    hijos.append(QString::number(i+1) + ")" + QString::number(personaActual->listaHijos[i]->id) + "\n");
            }
            ui->tablaPersonas->setItem(insertRow, 8,new QTableWidgetItem(hijos));//HIJOS
        }
        else
            ui->tablaPersonas->setItem(insertRow, 8,new QTableWidgetItem("No tiene"));//NO TIENE HIJOS

        QTableWidgetItem *item = new QTableWidgetItem;
        item->setData(Qt::EditRole, personaActual->pecados[0]);
        ui->tablaPersonas->setItem(insertRow, 9,item);//LUJURIA

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setData(Qt::EditRole, personaActual->pecados[1]);
        ui->tablaPersonas->setItem(insertRow,10,item2);//GULA

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item3->setData(Qt::EditRole, personaActual->pecados[2]);
        ui->tablaPersonas->setItem(insertRow,11,item3);//AVARICIA

        QTableWidgetItem *item4 = new QTableWidgetItem;
        item4->setData(Qt::EditRole, personaActual->pecados[3]);
        ui->tablaPersonas->setItem(insertRow,12,item4);//PEREZA

        QTableWidgetItem *item5 = new QTableWidgetItem;
        item5->setData(Qt::EditRole, personaActual->pecados[4]);
        ui->tablaPersonas->setItem(insertRow,13,item5);//IRA

        QTableWidgetItem *item6 = new QTableWidgetItem;
        item6->setData(Qt::EditRole, personaActual->pecados[5]);
        ui->tablaPersonas->setItem(insertRow,14,item6);//ENVIDIA

        QTableWidgetItem *item7 = new QTableWidgetItem;
        item7->setData(Qt::EditRole, personaActual->pecados[6]);
        ui->tablaPersonas->setItem(insertRow,15,item7);//SOBERBIA

        sumaPecados = 0;
        for (int i = 0; i < 7 ; i++){
            sumaPecados += personaActual->pecados[i];
        }
        QTableWidgetItem *item8 = new QTableWidgetItem;
        item8->setData(Qt::EditRole, sumaPecados);
        ui->tablaPersonas->setItem(insertRow,16,item8);//Total Pecados
    }
}

void VentanaInfoPersonas::on_pushButton_clicked()//Apellido
{
    filtrarLista(ui->filtApellidos->currentText(),2);
}

void VentanaInfoPersonas::on_pushButton_2_clicked()//País
{
    filtrarLista(ui->filtPaises->currentText(),3);
}

void VentanaInfoPersonas::on_pushButton_3_clicked()//Creencia
{
    filtrarLista(ui->filtCreencias->currentText(),4);
}

void VentanaInfoPersonas::on_pushButton_4_clicked()//Continente
{
    //filtrarLista(ui->filtContinentes->currentText());
}

void VentanaInfoPersonas::on_pushButton_5_clicked()//Profesiones
{
    filtrarLista(ui->filtProfesiones->currentText(),5);
}
void VentanaInfoPersonas::filtrarLista(QString filter, int columna){

    for( int i = 0; i < ui->tablaPersonas->rowCount(); ++i )
    {
        bool match = false;

        QTableWidgetItem *item = ui->tablaPersonas->item( i, columna );
        if( item->text().contains(filter) )
        {
            match = true;

        }

        ui->tablaPersonas->setRowHidden( i, !match );
    }
}

void VentanaInfoPersonas::setComboBoxes(){
    InformacionPersona* infoPers = new InformacionPersona();
    for (int i = 0; i < 1000; i++){//Apellidos
        ui->filtApellidos->addItem(infoPers->listaApellidos[i]);
    }
    for (int i = 0; i < 100; i++){//Países
        ui->filtPaises->addItem(infoPers->listaPaises[i][0]);
    }
    for (int i = 0; i < 50; i++){//Profesiones
        ui->filtProfesiones->addItem(infoPers->listaProfesiones[i]);
    }
    for (int i = 0; i < 10; i++){//Creencias
        ui->filtCreencias->addItem(infoPers->listaCreencias[i]);
    }
    QString continentes [5] = {"África","América","Asia","Europa","Oceanía"};
    for (int i = 0; i < 5; i++){//Continentes
        ui->filtContinentes->addItem(continentes[i]);
    }

}

void VentanaInfoPersonas::on_pushButton_6_clicked()//Mostrar todo
{
    for( int i = 0; i < ui->tablaPersonas->rowCount(); ++i )
    {
        ui->tablaPersonas->setRowHidden( i, false );
    }
}
