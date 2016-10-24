#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <ctime>
#include <cstdlib>//RANDOMS
#include <time.h> //Tiempo
#include <QString>
#include <QFile>//Manejo de archivos
#include <QMessageBox>
#include <QTextStream>

#include <QDebug>
struct InformacionPersona;
struct NodoPersona;
struct ListaPersonas;

struct InformacionPersona {
    int randomsUnicos [9999999];
    QString listaNombres [1000];
    QString listaApellidos [1000];
    QString listaPaises [100] [2];//100 filas 2 columnas  (pais, continente)
    QString listaProfesiones [50];
    QString listaCreencias [10];

    InformacionPersona(){
        setListaNombres();
        setListaApellidos();
        setListaPaises();
        setListaCreencias();
        setListaProfesiones();
        setListaRandoms();
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

    /**
     * Carga desde un archivo de texto las profesiones del mundo
     * @brief setListaProfesiones
     */
    void setListaProfesiones(){
        int i = 0;
        QFile archivoProfesiones(":/recursos/archivosTexto/Profesion.txt");
        if(!archivoProfesiones.open(QIODevice::ReadOnly)) {
            QMessageBox::information(0, "error", archivoProfesiones.errorString());
        }

        QTextStream in(&archivoProfesiones);

        //Son 50 profesiones
        while(!in.atEnd()) {
            QString profesion = in.readLine();
            listaProfesiones[i++] = profesion;
        }

        archivoProfesiones.close();
    }

    void setListaRandoms(){
        //Inicializo el array
        for(int i = 0; i < 10000000; i++)
            randomsUnicos[i] = i;
        //Le hago un shuffle al array
        int temp;
        for (int i = 9999999; i >= 0; i--){
            int random = (rand() % (int)(i + 1));//min + (rand() % (int)(max - min + 1)) -> 0 + (rand() % (int)(max - 0 + 1))
            temp = randomsUnicos[i];
            randomsUnicos[i] = randomsUnicos[random];
            randomsUnicos[random] = temp;

        }
    }
};

struct NodoPersona {
    NodoPersona* siguiente;

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

    NodoPersona (int _id, QString _nombre, QString _apellido, QString _pais, QString _creencia, QString _profesion, QString _correo){
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        correo = _correo;
        fechaNacimiento = setFechaNacimiento();
        setPecados();
        siguiente = nullptr;
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
struct ListaPersonas{
    NodoPersona* primeraPersona;
    InformacionPersona* infoPersona;

    ListaPersonas(){

        infoPersona = new InformacionPersona();
        primeraPersona = nullptr;

    }

    void insertarPersona(int idSiguiente){
        qDebug()<<idSiguiente;
        srand(time(NULL));
        int randomMil = (rand() % (int)(1000 + 1));
        int randomMil2 = (rand() % (int)(1000 + 1));
        int randomCien = (rand() % (int)(100 + 1));
        int randomCincuenta = (rand() % (int)(50 + 1));
        int randomDiez = (rand() % (int)(10 + 1));

        if(primeraPersona == nullptr)
            primeraPersona = new NodoPersona(infoPersona->randomsUnicos[idSiguiente],infoPersona->listaNombres[randomMil],
                                             infoPersona->listaApellidos[randomMil2], infoPersona->listaPaises[randomCien][0],
                                             infoPersona->listaCreencias[randomDiez], infoPersona->listaProfesiones[randomCincuenta],"Correo");

        else{

            NodoPersona* tmp = primeraPersona;
            while (tmp->siguiente != nullptr)
                tmp = tmp->siguiente;

            tmp->siguiente = new NodoPersona(infoPersona->randomsUnicos[idSiguiente],infoPersona->listaNombres[randomMil],
                                  infoPersona->listaApellidos[randomMil2], infoPersona->listaPaises[randomCien][0],
                                  infoPersona->listaCreencias[randomDiez], infoPersona->listaProfesiones[randomCincuenta],"Correo");
        }
    }

    int largo(){
        int largoLista = 0;
        NodoPersona* tmp = primeraPersona;
        while(tmp != nullptr){
            tmp = tmp->siguiente;
            largoLista++;
        }
        return largoLista;
    }
};












#endif // ESTRUCTURAS_H
