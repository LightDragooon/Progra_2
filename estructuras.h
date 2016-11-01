#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <ctime>
#include <cstdlib>//RANDOMS
#include <random> //Mersenne Twister  con periodo de 2^32 -1
#include <time.h> //Tiempo
#include <QString>
#include <QFile>//Manejo de archivos
#include <QMessageBox>
#include <QTextStream>

#include <QDebug>
struct InformacionPersona;
struct NodoPersona;
struct ListaPersonas;
struct NodoArbolPersonas;
struct ArbolPersonas;

struct InformacionPersona {
    unsigned int randomsUnicos [9999999];
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

        //GENERADOR PARA MIL 1
        std::mt19937 randomizador (time(NULL));

        int temp;
        for (int i = 9999999; i >= 0; i--){
            std::uniform_real_distribution<double> distRandomizador(0.0, i);
            int random = distRandomizador(randomizador);
            temp = randomsUnicos[i];
            randomsUnicos[i] = randomsUnicos[random];
            randomsUnicos[random] = temp;

        }
    }
};


struct NodoPersona {
    NodoPersona* siguiente;

    unsigned int id;
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
    NodoPersona* listaHijos[8];
    NodoPersona (int _id, QString _nombre, QString _apellido, QString _pais, QString _continente, QString _creencia, QString _profesion){
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        pais = _pais;
        creencia = _creencia;
        profesion = _profesion;
        correo = setCorreo(_continente);
        fechaNacimiento = setFechaNacimiento();
        setPecados();
        setListaHijos();
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
        fecha = QString::number(ahora->tm_mday)+"/"+QString::number(ahora->tm_mon+1)+"/"+QString::number(ahora->tm_year+1900)+"\n"+
                QString::number(ahora->tm_hour)+":"+QString::number(ahora->tm_min)+":"+QString::number(ahora->tm_sec);
        return fecha;
    }

    QString setCorreo(QString continente){
        if (continente == "África")
            return "Correo África";
        else if (continente == "América")
            return "Correo América";
        else if (continente == "Asia")
            return "Correo Asia";
        else if (continente == "Europa")
            return "Correo Europa";
        else if (continente == "Oceanía")
            return "Correo Oceanía";
        else
            return "Inválido";

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

    void setListaHijos(){
        for (int i = 0; i < 8; i++){
            listaHijos[i] = nullptr;
        }
    }

};

/**
 * @brief The nodoArbolPersonas struct
 * Este arbol está compuesto de punteros a personas y se puede construir de varias formas
 *
 */
struct NodoArbolPersonas{

    NodoArbolPersonas* hijoIzquierdo;
    NodoArbolPersonas* hijoDerecho;

    NodoPersona* persona;

    NodoArbolPersonas(NodoPersona* _persona){
        hijoIzquierdo = nullptr;
        hijoDerecho = nullptr;

        persona =_persona;
    }

};

struct ArbolPersonas{
    NodoArbolPersonas* raiz;

    ArbolPersonas(){
        raiz = nullptr;
    }
    //Métodos


    int cantidadNodosAux(){
        if (raiz == nullptr)
            return 0;
        else
            return cantidadNodos(raiz);
    }
    int cantidadNodos(NodoArbolPersonas* raiz){
        if (raiz == nullptr)
            return 0;
        else
            return 1 + cantidadNodos (raiz->hijoDerecho) + cantidadNodos (raiz->hijoIzquierdo);
    }

    NodoArbolPersonas* FindInsertionPoint(NodoPersona* persona, NodoArbolPersonas * parent) // this should be private
    {
        NodoArbolPersonas* insertPoint = persona->id < parent->persona->id
            ? parent->hijoIzquierdo
            : parent->hijoDerecho;

        return insertPoint
            ? FindInsertionPoint(persona, insertPoint)
            : parent;
    }

    void insertarPersona(NodoPersona* persona)  // this should be public
    {
        if(!raiz)
        {
            raiz = new NodoArbolPersonas(persona);
            return;
        }

        NodoArbolPersonas* parent = FindInsertionPoint(persona, raiz);

        if(persona->id < parent->persona->id)
            parent->hijoIzquierdo = new NodoArbolPersonas(persona); // see comment on Node constructor above
        else
            parent->hijoDerecho = new NodoArbolPersonas(persona); // see comment on Node constructor above
    }

    NodoPersona* obtenerHijo (NodoArbolPersonas* raiz, NodoPersona* personaActual, bool nuevoHijo){
        //GENERADOR BINARIO
        std::mt19937 generadorBinario (time(NULL));
        std::uniform_real_distribution<double> disBinaria(0.0, 1.0);
        if(raiz != nullptr){
            if(raiz->persona->id != personaActual->id){//No puede ser él mismo hijo de él mismo
                //Debo revisar si ya es hijo
                for (int h = 0; h < 8 ; h++){
                    if(personaActual->listaHijos[h] != nullptr){
                        if(raiz->persona->id == personaActual->listaHijos[h]->id)//Significa que ya es hijo de el
                            nuevoHijo = false;//NO ES NUEVO HIJO
                    }

                }

                if(nuevoHijo){
                    //Reviso si es el padre de la persona
                    if(raiz->persona->listaHijos[0] != nullptr){
                        for (int i = 0; i < 8; i++){
                            if(raiz->persona->listaHijos[i] != nullptr){
                                if(raiz->persona->listaHijos[i]->id == personaActual->id){
                                    //Si entro acá es porque la persona contenida en la raiz es el padre de la persona a la que intento agregar un hijo
                                    //Debo movilizarme a la izquierda o derecha esto lo hago aleatoriamente
                                    if(disBinaria(generadorBinario) == 0)//Derecha
                                        return obtenerHijo (raiz->hijoDerecho , personaActual, true);
                                    else
                                        return obtenerHijo (raiz->hijoDerecho , personaActual, true);
                                }

                                //Debo revisar si es el abuelo
                                if(raiz->persona->listaHijos[0]->listaHijos[0] != nullptr){
                                    for (int j = 0; j < 8; j++){
                                        if(raiz->persona->listaHijos[i]->listaHijos[j] != nullptr){
                                            if(raiz->persona->listaHijos[i]->listaHijos[j]->id == personaActual->id){
                                                //Si entro acá es porque la persona contenida en la raiz es el abuelo de la persona a la que intento agregar un hijo
                                                //Debo movilizarme a la izquierda o derecha esto lo hago aleatoriamente
                                                //GENERADOR BINARIO
                                                if(disBinaria(generadorBinario) == 0)//Derecha
                                                    return obtenerHijo (raiz->hijoDerecho ,personaActual, true);
                                                else
                                                    return obtenerHijo (raiz->hijoDerecho , personaActual, true);
                                            }
                                        }

                                    }
                                }//If de abuelos
                            }//Validación
                        }//Termina el for con i
                    }
                    //Si logré salir  del for es porque no es el papa ni el abuelo y entonces puede ser un hijo, PERO debo revisar la nacionalidad
                    //Puede ser también que no tenga hijos
                    if(raiz->persona->pais == personaActual->pais)
                        return raiz->persona;
                }

            }
            //Si entro acá es porque la persona no puede ser hijo de ella misma
            //Debo movilizarme a la izquierda o derecha esto lo hago aleatoriamente
            if(disBinaria(generadorBinario) == 0)//Derecha
                return obtenerHijo (raiz->hijoDerecho ,personaActual, true);
            else
                return obtenerHijo (raiz->hijoDerecho ,personaActual, true);
        }
        return nullptr;
    }
};

struct ListaPersonas{
    NodoPersona* primeraPersona;
    InformacionPersona* infoPersona;

    ListaPersonas(){

        infoPersona = new InformacionPersona();
        primeraPersona = nullptr;

    }


    int insertarPersonaCantidad(int idInicial, int cantidadPersonas){
        srand(time(NULL));
        int randomMil;
        int randomMil2;
        int randomCien;
        int randomCincuenta;
        int randomDiez;

        NodoPersona* tmp;
        NodoPersona* tmpAnterior;
        bool hayInsertar;

        //GENERADOR PARA MIL 1
        std::mt19937 generadorMil1 (time(NULL));
        std::uniform_real_distribution<double> disMil1(1.0, 999.0);
        //GENERADOR PARA MIL 2
        std::mt19937 generadorMil2 (time(NULL));
        std::uniform_real_distribution<double> disMil2(0.0, 999.0);
        //GENERADOR PARA CIEN
        std::mt19937 generadorCien (time(NULL));
        std::uniform_real_distribution<double> disCien(0.0, 99.0);
        //GENERADOR PARA CINCUENTA
        std::mt19937 generadorCincuenta (time(NULL));
        std::uniform_real_distribution<double> disCincuenta(0.0, 49.0);
        //GENERADOR PARA DIEZ
        std::mt19937 generadorDiez (time(NULL));
        std::uniform_real_distribution<double> disDiez(0.0, 9.0);


        for (int i = 0; i < cantidadPersonas; i++){
            qDebug()<<idInicial;
            randomMil = disMil1(generadorMil1);
            randomMil2 = disMil2(generadorMil2);
            randomCien = disCien(generadorCien);
            randomCincuenta = disCincuenta(generadorCincuenta);
            randomDiez = disDiez(generadorDiez);
            if(primeraPersona == nullptr)
                primeraPersona = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                                 infoPersona->listaNombres[randomMil],
                                                 infoPersona->listaApellidos[randomMil2],
                                                 infoPersona->listaPaises[randomCien][0],
                                                 infoPersona->listaPaises[randomCien][1],
                                                 infoPersona->listaCreencias[randomDiez],
                                                 infoPersona->listaProfesiones[randomCincuenta]);

            else{

                tmp = primeraPersona;
                tmpAnterior = nullptr;
                hayInsertar = true;
                while (tmp->siguiente != nullptr){
                    if(tmp->id > infoPersona->randomsUnicos[idInicial]){//  Debo de insertarlo antes del nodo tmp

                        if(tmpAnterior == nullptr){
                            primeraPersona = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                    infoPersona->listaNombres[randomMil],
                                    infoPersona->listaApellidos[randomMil2],
                                    infoPersona->listaPaises[randomCien][0],
                                    infoPersona->listaPaises[randomCien][1],
                                    infoPersona->listaCreencias[randomDiez],
                                    infoPersona->listaProfesiones[randomCincuenta]);
                            primeraPersona->siguiente = tmp;
                            hayInsertar = false;
                            break;
                        }
                        else{
                            tmpAnterior->siguiente = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                                                    infoPersona->listaNombres[randomMil],
                                                                    infoPersona->listaApellidos[randomMil2],
                                                                    infoPersona->listaPaises[randomCien][0],
                                                                    infoPersona->listaPaises[randomCien][1],
                                                                    infoPersona->listaCreencias[randomDiez],
                                                                    infoPersona->listaProfesiones[randomCincuenta]);
                            tmpAnterior->siguiente->siguiente = tmp;
                            hayInsertar = false;

                            break;
                        }

                    }

                    tmpAnterior = tmp;
                    tmp = tmp->siguiente;
                }

                //Si llega acá es porque se debe insertar al final
                if(hayInsertar){
                    tmp->siguiente = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                                     infoPersona->listaNombres[randomMil],
                                                     infoPersona->listaApellidos[randomMil2],
                                                     infoPersona->listaPaises[randomCien][0],
                                                     infoPersona->listaPaises[randomCien][1],
                                                     infoPersona->listaCreencias[randomDiez],
                                                     infoPersona->listaProfesiones[randomCincuenta]);
                }

            }
        }
        return idInicial;//Es el último que usó
    }


    int largo(){
        if (primeraPersona == nullptr)
            return 0;
        else{
            int largoTotal = 0;
            NodoPersona* tmp = primeraPersona;
            while (tmp != nullptr){
                tmp = tmp -> siguiente;
                largoTotal++;
            }
            return largoTotal;
        }
    }

    /**
     * Genera los pecados de los humanos >:D
     * Se generan 7 randoms distintos para cada pecado del 0 - 100
     * @brief generarPecados
     */
    void generarPecados(){
        if (primeraPersona != nullptr){
            //Temporal con el que recorro la lista
            NodoPersona* tmp = primeraPersona;
            //GENERADOR DE RANDOMS DE 0 - 100
            std::mt19937 generadorPecados (time(NULL));
            std::uniform_real_distribution<double> disPecados(0.0, 101.0);


            //Entro al ciclo para recorrer cada humano y de paso le sumo pecados
            while (tmp != nullptr){


                tmp->pecados[0] += disPecados(generadorPecados);

                tmp->pecados[1] += disPecados(generadorPecados);

                tmp->pecados[2] += disPecados(generadorPecados);

                tmp->pecados[3] += disPecados(generadorPecados);

                tmp->pecados[4] += disPecados(generadorPecados);

                tmp->pecados[5] += disPecados(generadorPecados);

                tmp->pecados[6] += disPecados(generadorPecados);

                //Paso al siguiente humano
                tmp = tmp -> siguiente;
            }
        }

    }

    NodoPersona* buscarPersonaPos (int posicion){
        NodoPersona* tmp = primeraPersona;
        bool existe = false;
        for (int i = 0; i <= posicion;i++){
            if(i == posicion)
                existe = true;
            if (tmp->siguiente == nullptr)
                break;
            tmp = tmp->siguiente;
        }
        if(existe)
            return tmp;
        else
            return nullptr;
    }
    /**
     * @brief cantidadApellido
     * @return La cantidad de personas que poseen ese apellido en específico
     */
    int cantidadApellido(QString apellidoBuscar){
        if (primeraPersona == nullptr)
            return 0;
        else{
            int cantidad = 0;
            NodoPersona* tmp = primeraPersona;
            while (tmp != nullptr){

                if(tmp->apellido == apellidoBuscar)
                    cantidad++;
                tmp = tmp -> siguiente;
            }
            return cantidad;
        }
    }

    NodoPersona* buscarPersonaApellidoLimit (int limitador, QString apellidoBuscar){
        NodoPersona* tmp = primeraPersona;

        while (tmp != nullptr){

            if(tmp->apellido == apellidoBuscar){
                if(limitador-- == 0)
                    return tmp;
            }
            tmp = tmp -> siguiente;
        }
        return nullptr;

    }

    void agregarHijos (){

        NodoPersona* personaActual = primeraPersona;
        NodoPersona* posibleHijo;
        ArbolPersonas* arbolApellidos;
        int cantHijos;
        //GENERADOR DE RANDOMS DE 0 - 8
        std::mt19937 cantidadHijos (time(NULL));
        std::uniform_real_distribution<double> disHijos(0.0, 9.0);// 0 - 8
        qDebug()<<"Agregando Hijos";
        while (personaActual != nullptr){
            //Creo el arbol correspondiente a la persona
            arbolApellidos = new ArbolPersonas();
            //Posible hijo se crea después de el
            posibleHijo = primeraPersona;
            //Ciclo para agregar al arbol aquellos con igual apellido
            while (posibleHijo != nullptr){
                if(personaActual->apellido == posibleHijo->apellido){
                    arbolApellidos->insertarPersona(posibleHijo);
                }
                posibleHijo = posibleHijo->siguiente;
            }
            //Tengo el arbol con los appellidos
            cantHijos = disHijos(cantidadHijos);
            for (int i = 0; i < cantHijos; i++){
                posibleHijo = arbolApellidos->obtenerHijo(arbolApellidos->raiz, personaActual, true);
                if (posibleHijo != nullptr)
                    personaActual->listaHijos[i] = posibleHijo;
                else
                    break;
            }

            personaActual = personaActual->siguiente;
        }

    }

};











#endif // ESTRUCTURAS_H
