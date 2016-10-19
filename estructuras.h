#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <ctime>
#include <cstdlib>//RANDOMS
#include <QString>
#include <QFile>//Manejo de archivos
#include <QMessageBox>
#include <QTextStream>

#include <QDebug>

struct nodoPersona {
    int id;
    QString nombre;
    QString apellido;
    QString pais;
    QString creencia;
    QString profesion;
    QString correo;
    QString fechaNacimiento;
    //Pecados
    // [Lujuria, Gula, Avaricia, Pereza, Ira, Envidia, Soberbia]
    int pecados[7];
    //Lista de hijos

    nodoPersona (int _id, QString _nombre, QString _apellido, QString _pais, QString _creencia, QString _profesion, QString _correo){
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        correo = _correo;
        fechaNacimiento = setFechaNacimiento();
        setPecados();
    }
    /**
     * @brief setFechaNacimiento
     * @return fecha actual con el formato dd/mm/aa hh:mm:ss
     */
    QString setFechaNacimiento (){
        QString fecha;
        time_t tiempoAhora = time (0);
        struct tm * ahora = localtime(& tiempoAhora);
        fecha = "Fecha de nacimiento: "+QString::number(ahora->tm_mday)+"/"+QString::number(ahora->tm_mon+1)+"/"+QString::number(ahora->tm_year+1900)+
                "\nHora de nacimiento: "+QString::number(ahora->tm_hour)+":"+QString::number(ahora->tm_min)+":"+QString::number(ahora->tm_sec);
        return fecha;
    }
    /**
     * Establece los pecados en 0
     * @brief setPecados
     */
    void setPecados(){
        for (int i = 0; i < 7; i++){
            pecados[i] = 0;
        }
    }

};

struct informacionPersona {
    QString listaNombres [1000];
    QString listaApellidos [1000];
    QString listaPaises [100] [2];//100 filas 2 columnas  (pais, continente)
    QString listaProfesiones [50];
    QString listaCreencias [10];

    informacionPersona(){
        setListaNombres();
        setListaApellidos();
        setListaPaises();
    }

    /**
     * Carga desde un archivo de texto los nombres de las personas
     * @brief setListaNombres
     */
    void setListaNombres(){
        int i = 0;
        QFile archivoNombres(":/recursos/archivosTexto/Nombres.txt");
        if(!archivoNombres.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", archivoNombres.errorString());
        }

        QTextStream in(&archivoNombres);

        //Son 1000 nombres
        while(!in.atEnd()) {
            QString nombre = in.readLine();
            listaNombres[i++] = nombre;
        }

        archivoNombres.close();
    }

    /**
     * Carga desde un archivo de texto los apellidos de las personas
     * @brief setListaApellidos
     */
    void setListaApellidos(){
        int i = 0;
        QFile archivoApellidos(":/recursos/archivosTexto/Apellidos.txt");
        if(!archivoApellidos.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", archivoApellidos.errorString());
        }

        QTextStream in(&archivoApellidos);

        //Son 1000 apellidos
        while(!in.atEnd()) {
            QString apellido = in.readLine();
            listaApellidos[i++] = apellido;
        }

        archivoApellidos.close();
    }

    /**
     * Carga desde un archivo de texto los países del mundo (100)
     * @brief setListaPaises
     */
    void setListaPaises(){
        int i = 0;
        QFile archivoPaises(":/recursos/archivosTexto/Paises.txt");
        if(!archivoPaises.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", archivoPaises.errorString());
        }

        QTextStream in(&archivoPaises);

        //Son 100 paises
        //Dentro del archivo se encuentran : "pais-continente"
        while(!in.atEnd()) {
            QString tempPaisCont = in.readLine();
            QStringList paisCont = tempPaisCont.split('-', QString::SkipEmptyParts);
            qDebug()<<i;
            listaPaises[i][0] = paisCont[0];
            listaPaises[i++][1] = paisCont[1];
        }

        archivoPaises.close();
    }

    /**
     * Carga desde un archivo de texto las creencias del mundo (10)
     * @brief setListaCreencias
     */
    void setListaCreencias(){
        int i = 0;
        QFile archivoCreencias(":/recursos/archivosTexto/Creencias.txt");
        if(!archivoCreencias.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", archivoCreencias.errorString());
        }

        QTextStream in(&archivoCreencias);

        //Son 10 creencias
        while(!in.atEnd()) {
            QString creencia = in.readLine();
            listaCreencias[i++] = creencia;
        }

        archivoCreencias.close();
    }
};










#endif // ESTRUCTURAS_H
