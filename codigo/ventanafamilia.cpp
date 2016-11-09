#include "ventanafamilia.h"
#include "ui_ventanafamilia.h"

VentanaFamilia::VentanaFamilia(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VentanaFamilia)
{
    ui->setupUi(this);
}

VentanaFamilia::~VentanaFamilia()
{
    delete ui;
}
void VentanaFamilia::setListaPersonas(NodoPersona* nodoAbuelo){
    NodoPersona* personaActual;
    QString hijos= "";
    int sumaPecados;
    //Inserto al abuelo en su tabla
    //Cantidad de filas actuales
    int insertRow = ui->abuelo->rowCount();

    //Agrego al final de la tabla
    ui->abuelo->insertRow(insertRow);

    //Agrego los objetos en las columnas correspondientes
    ui->abuelo->setItem(insertRow, 0,new QTableWidgetItem(QString::number(nodoAbuelo->id)));//ID
    ui->abuelo->setItem(insertRow, 1,new QTableWidgetItem(nodoAbuelo->nombre));//NOMBRE
    ui->abuelo->setItem(insertRow, 2,new QTableWidgetItem(nodoAbuelo->apellido));//APELLIDO
    ui->abuelo->setItem(insertRow, 3,new QTableWidgetItem(nodoAbuelo->pais));//PAÍS
    ui->abuelo->setItem(insertRow, 4,new QTableWidgetItem(nodoAbuelo->creencia));//CREENCIA
    ui->abuelo->setItem(insertRow, 5,new QTableWidgetItem(nodoAbuelo->profesion));//PROFESIÓN
    ui->abuelo->setItem(insertRow, 6,new QTableWidgetItem(nodoAbuelo->correo));//CORREO
    ui->abuelo->setItem(insertRow, 7,new QTableWidgetItem(nodoAbuelo->fechaNacimiento));//NACIMIENTO

    if(nodoAbuelo->listaHijos[0] != nullptr){
        hijos= "";
        for (int i = 0; i < 8; i++){
            if (nodoAbuelo->listaHijos[i] != nullptr)
                hijos.append(QString::number(i+1) + ")" + QString::number(nodoAbuelo->listaHijos[i]->id) + "\n");
        }
        ui->abuelo->setItem(insertRow, 8,new QTableWidgetItem(hijos));//HIJOS
    }
    else
        ui->abuelo->setItem(insertRow, 8,new QTableWidgetItem("No tiene"));//NO TIENE HIJOS

    QTableWidgetItem *item = new QTableWidgetItem;
    item->setData(Qt::EditRole, nodoAbuelo->pecados[0]);
    ui->abuelo->setItem(insertRow, 9,item);//LUJURIA

    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setData(Qt::EditRole, nodoAbuelo->pecados[1]);
    ui->abuelo->setItem(insertRow,10,item2);//GULA

    QTableWidgetItem *item3 = new QTableWidgetItem;
    item3->setData(Qt::EditRole, nodoAbuelo->pecados[2]);
    ui->abuelo->setItem(insertRow,11,item3);//AVARICIA

    QTableWidgetItem *item4 = new QTableWidgetItem;
    item4->setData(Qt::EditRole, nodoAbuelo->pecados[3]);
    ui->abuelo->setItem(insertRow,12,item4);//PEREZA

    QTableWidgetItem *item5 = new QTableWidgetItem;
    item5->setData(Qt::EditRole, nodoAbuelo->pecados[4]);
    ui->abuelo->setItem(insertRow,13,item5);//IRA

    QTableWidgetItem *item6 = new QTableWidgetItem;
    item6->setData(Qt::EditRole, nodoAbuelo->pecados[5]);
    ui->abuelo->setItem(insertRow,14,item6);//ENVIDIA

    QTableWidgetItem *item7 = new QTableWidgetItem;
    item7->setData(Qt::EditRole, nodoAbuelo->pecados[6]);
    ui->abuelo->setItem(insertRow,15,item7);//SOBERBIA

    sumaPecados = 0;
    for (int i = 0; i < 7 ; i++){
        sumaPecados += nodoAbuelo->pecados[i];
    }
    QTableWidgetItem *item8 = new QTableWidgetItem;
    item8->setData(Qt::EditRole, sumaPecados);
    ui->abuelo->setItem(insertRow,16,item8);//SOBERBIA

    //Ahora voy a insertar los hijos y nietos al mismo tiempo

    for(int i = 0; i < 8; i++){//8 es la cantidad máxima
        if(nodoAbuelo->listaHijos[i] != nullptr){//Si no es nulo inserto al hijo
            personaActual = nodoAbuelo->listaHijos[i];
            //Cantidad de filas actuales
            insertRow = ui->hijos->rowCount();

            //Agrego al final de la tabla
            ui->hijos->insertRow(insertRow);

            //Agrego los objetos en las columnas correspondientes
            ui->hijos->setItem(insertRow, 0,new QTableWidgetItem(QString::number(personaActual->id)));//ID
            ui->hijos->setItem(insertRow, 1,new QTableWidgetItem(personaActual->nombre));//NOMBRE
            ui->hijos->setItem(insertRow, 2,new QTableWidgetItem(personaActual->apellido));//APELLIDO
            ui->hijos->setItem(insertRow, 3,new QTableWidgetItem(personaActual->pais));//PAÍS
            ui->hijos->setItem(insertRow, 4,new QTableWidgetItem(personaActual->creencia));//CREENCIA
            ui->hijos->setItem(insertRow, 5,new QTableWidgetItem(personaActual->profesion));//PROFESIÓN
            ui->hijos->setItem(insertRow, 6,new QTableWidgetItem(personaActual->correo));//CORREO
            ui->hijos->setItem(insertRow, 7,new QTableWidgetItem(personaActual->fechaNacimiento));//NACIMIENTO

            if(personaActual->listaHijos[0] != nullptr){
                hijos= "";
                for (int j = 0; j < 8;j++){
                    if (personaActual->listaHijos[j] != nullptr)
                        hijos.append(QString::number(j+1) + ")" + QString::number(personaActual->listaHijos[j]->id) + "\n");
                }
                ui->hijos->setItem(insertRow, 8,new QTableWidgetItem(hijos));//HIJOS
            }
            else
                ui->hijos->setItem(insertRow, 8,new QTableWidgetItem("No tiene"));//NO TIENE HIJOS

            QTableWidgetItem *item = new QTableWidgetItem;
            item->setData(Qt::EditRole, personaActual->pecados[0]);
            ui->hijos->setItem(insertRow, 9,item);//LUJURIA

            QTableWidgetItem *item2 = new QTableWidgetItem;
            item2->setData(Qt::EditRole, personaActual->pecados[1]);
            ui->hijos->setItem(insertRow,10,item2);//GULA

            QTableWidgetItem *item3 = new QTableWidgetItem;
            item3->setData(Qt::EditRole, personaActual->pecados[2]);
            ui->hijos->setItem(insertRow,11,item3);//AVARICIA

            QTableWidgetItem *item4 = new QTableWidgetItem;
            item4->setData(Qt::EditRole, personaActual->pecados[3]);
            ui->hijos->setItem(insertRow,12,item4);//PEREZA

            QTableWidgetItem *item5 = new QTableWidgetItem;
            item5->setData(Qt::EditRole, personaActual->pecados[4]);
            ui->hijos->setItem(insertRow,13,item5);//IRA

            QTableWidgetItem *item6 = new QTableWidgetItem;
            item6->setData(Qt::EditRole, personaActual->pecados[5]);
            ui->hijos->setItem(insertRow,14,item6);//ENVIDIA

            QTableWidgetItem *item7 = new QTableWidgetItem;
            item7->setData(Qt::EditRole, personaActual->pecados[6]);
            ui->hijos->setItem(insertRow,15,item7);//SOBERBIA

            sumaPecados = 0;
            for (int j = 0; j < 7 ; j++){
                sumaPecados += personaActual->pecados[j];
            }
            QTableWidgetItem *item8 = new QTableWidgetItem;
            item8->setData(Qt::EditRole, sumaPecados);
            ui->hijos->setItem(insertRow,16,item8);//Suma pecados
        }
        //Nietos
        if(personaActual != nullptr){
            NodoPersona* auxNieto;
            for(int j = 0; j < 8; j++){//8 es la cantidad máxima
                if(personaActual->listaHijos[j] != nullptr){//Si no es nulo inserto al hijo
                    auxNieto = personaActual->listaHijos[j];
                    //Cantidad de filas actuales
                    insertRow = ui->nietos->rowCount();

                    //Agrego al final de la tabla
                    ui->nietos->insertRow(insertRow);

                    //Agrego los objetos en las columnas correspondientes
                    ui->nietos->setItem(insertRow, 0,new QTableWidgetItem(QString::number(auxNieto->id)));//ID
                    ui->nietos->setItem(insertRow, 1,new QTableWidgetItem(auxNieto->nombre));//NOMBRE
                    ui->nietos->setItem(insertRow, 2,new QTableWidgetItem(auxNieto->apellido));//APELLIDO
                    ui->nietos->setItem(insertRow, 3,new QTableWidgetItem(auxNieto->pais));//PAÍS
                    ui->nietos->setItem(insertRow, 4,new QTableWidgetItem(auxNieto->creencia));//CREENCIA
                    ui->nietos->setItem(insertRow, 5,new QTableWidgetItem(auxNieto->profesion));//PROFESIÓN
                    ui->nietos->setItem(insertRow, 6,new QTableWidgetItem(auxNieto->correo));//CORREO
                    ui->nietos->setItem(insertRow, 7,new QTableWidgetItem(auxNieto->fechaNacimiento));//NACIMIENTO

                    if(auxNieto->listaHijos[0] != nullptr){
                        hijos= "";
                        for (int k = 0; k < 8;k++){
                            if (auxNieto->listaHijos[k] != nullptr)
                                hijos.append(QString::number(k+1) + ")" + QString::number(auxNieto->listaHijos[k]->id) + "\n");
                        }
                        ui->nietos->setItem(insertRow, 8,new QTableWidgetItem(hijos));//HIJOS
                    }
                    else
                        ui->nietos->setItem(insertRow, 8,new QTableWidgetItem("No tiene"));//NO TIENE HIJOS

                    QTableWidgetItem *item = new QTableWidgetItem;
                    item->setData(Qt::EditRole, auxNieto->pecados[0]);
                    ui->nietos->setItem(insertRow, 9,item);//LUJURIA

                    QTableWidgetItem *item2 = new QTableWidgetItem;
                    item2->setData(Qt::EditRole, auxNieto->pecados[1]);
                    ui->nietos->setItem(insertRow,10,item2);//GULA

                    QTableWidgetItem *item3 = new QTableWidgetItem;
                    item3->setData(Qt::EditRole, auxNieto->pecados[2]);
                    ui->nietos->setItem(insertRow,11,item3);//AVARICIA

                    QTableWidgetItem *item4 = new QTableWidgetItem;
                    item4->setData(Qt::EditRole, auxNieto->pecados[3]);
                    ui->nietos->setItem(insertRow,12,item4);//PEREZA

                    QTableWidgetItem *item5 = new QTableWidgetItem;
                    item5->setData(Qt::EditRole, auxNieto->pecados[4]);
                    ui->nietos->setItem(insertRow,13,item5);//IRA

                    QTableWidgetItem *item6 = new QTableWidgetItem;
                    item6->setData(Qt::EditRole, auxNieto->pecados[5]);
                    ui->nietos->setItem(insertRow,14,item6);//ENVIDIA

                    QTableWidgetItem *item7 = new QTableWidgetItem;
                    item7->setData(Qt::EditRole, auxNieto->pecados[6]);
                    ui->nietos->setItem(insertRow,15,item7);//SOBERBIA

                    sumaPecados = 0;
                    for (int j = 0; j < 7 ; j++){
                        sumaPecados += auxNieto->pecados[j];
                    }
                    QTableWidgetItem *item8 = new QTableWidgetItem;
                    item8->setData(Qt::EditRole, sumaPecados);
                    ui->nietos->setItem(insertRow,16,item8);//Suma pecados
                }
            }//Fin del for
        }//Validación de no tener nietos
    }
}
