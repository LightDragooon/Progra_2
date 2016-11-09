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

#include "limits"

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
    //NodoPersona* anterior;
    unsigned int id;
    QString nombre;
    QString apellido;
    QString pais;
    QString continente;
    QString creencia;
    QString profesion;
    QString correo;
    QString fechaNacimiento;
    //Pecados
    // [Lujuria, Gula, Avaricia, Pereza, Ira, Envidia, Soberbia]
    int pecados[7];
    //Lista de hijos
    NodoPersona* listaHijos[8];
    //PADRE (Util en el bendito algoritmo de agregar hijos)
    NodoPersona* padre;
    NodoPersona (int _id, QString _nombre, QString _apellido, QString _pais, QString _continente, QString _creencia, QString _profesion){
        id = _id;
        nombre = _nombre;
        apellido = _apellido;
        pais = _pais;
        continente = _continente;
        creencia = _creencia;
        profesion = _profesion;
        correo = setCorreo(_continente);
        fechaNacimiento = setFechaNacimiento();
        setPecados();
        setListaHijos();
        siguiente = nullptr;
        padre = nullptr;
        //anterior = nullptr;
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
        //La persona actual es a quien quiero agregar hijos

        //GENERADOR BINARIO
        std::mt19937 generadorBinario (time(NULL));
        std::uniform_real_distribution<double> disBinaria(0.0, 1.0);
        if(raiz != nullptr){
            if(raiz->persona->id != personaActual->id){//No puede ser él mismo hijo de él mismo
                //Reviso si la persona actual y el posible hijo tienen padres.
                if(raiz->persona->padre != nullptr){
                    //Significa que ya este tiene un padre, entonces no es un posible hijo
                    if(disBinaria(generadorBinario) == 0)//Derecha
                        return obtenerHijo (raiz->hijoDerecho ,personaActual, true);
                    else
                        return obtenerHijo (raiz->hijoDerecho ,personaActual, true);
                }

                //Debo revisar si ya es hijo
                for (int i = 0; i < 8 ; i++){
                    if(personaActual->listaHijos[i] != nullptr){
                        if(raiz->persona->id == personaActual->listaHijos[i]->id)//Significa que ya es hijo de el
                            nuevoHijo = false;//NO ES NUEVO HIJO
                    }

                }

                if(nuevoHijo){
                    //Reviso si es el padre de la persona actual
                    if(raiz->persona->listaHijos[0] != nullptr){
                        for (int i = 0; i < 8; i++){
                            if(raiz->persona->listaHijos[i] != nullptr){
                                if(raiz->persona->listaHijos[i]->id == personaActual->id){
                                    //El ID de uno de los hijos es equivalente al ID de la persona actual
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

                                    }//Termina el for con j
                                }//If de abuelos
                            }//Validación
                        }//Termina el for con i
                    }



                    //Si logré salir  del for es porque no es el papa ni el abuelo y entonces puede ser un hijo, PERO debo revisar la nacionalidad
                    //Puede ser también que no tenga hijos
                    if(raiz->persona->pais == personaActual->pais)

                        return raiz->persona;//Finalmente retorno al hijo
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

    void insertarCustom(NodoPersona* personaInsertar){
        if (primeraPersona == nullptr)
            primeraPersona = personaInsertar;
        else{
            NodoPersona* tmp = primeraPersona;
            while (tmp->siguiente != nullptr)
                tmp = tmp->siguiente;
            tmp->siguiente = personaInsertar;
        }
    }

    /**
     * @brief insertarPersonaCantidad
     * @param idInicial
     * @param cantidadPersonas
     * @return ultimo ID utilizado
     */
    int insertarPersonaCantidad(int idInicial, int cantidadPersonas){
        srand(time(NULL));
        int randomMil;
        int randomMil2;
        int randomCien;
        int randomCincuenta;
        int randomDiez;

        NodoPersona* tmp;
        NodoPersona* tmpAnterior;
        NodoPersona* tmpInsertar;
        bool hayInsertar;

        //(unsigned int)

        /**
        //GENERADOR PARA MIL 1
        std::mt19937 generadorMil1 ((unsigned int)5+time(NULL)*10);//Nombres
        std::uniform_real_distribution<double> disMil1(1.0, 999.0);
        //GENERADOR PARA MIL 2
        std::mt19937 generadorMil2 (time(NULL));//Apellidos (unsigned int)
        std::uniform_real_distribution<double> disMil2(0.0, 999.0);
        //GENERADOR PARA CIEN
        std::mt19937 generadorCien (time(NULL));//Países    (unsigned int)4*time(NULL)+5
        std::uniform_real_distribution<double> disCien(0.0, 99.0);
        //GENERADOR PARA CINCUENTA
        std::mt19937 generadorCincuenta ((unsigned int)1-time(NULL)/8);//Profesiones
        std::uniform_real_distribution<double> disCincuenta(0.0, 49.0);
        //GENERADOR PARA DIEZ
        std::mt19937 generadorDiez ((unsigned int)(4-time(NULL)*2)/12);//Creencias
        std::uniform_real_distribution<double> disDiez(0.0, 9.0);
        */

        //GENERADOR
        std::mt19937 generador (time(NULL));
        //Distribución 1000
        std::uniform_real_distribution<double> disMil1(1.0, 999.0);//Nombres

        std::uniform_real_distribution<double> disMil2(0.0, 999.0);//Apellidos
        //Distribución 100
        std::uniform_real_distribution<double> disCien(0.0, 100.0);//Países
        //Distribución 50
        std::uniform_real_distribution<double> disCincuenta(0.0, 49.0);//Profesiones
        //Distribución 10
        std::uniform_real_distribution<double> disDiez(0.0, 9.0);//Creencias

        for (int i = 0; i < cantidadPersonas; i++){
            qDebug()<<idInicial;
            randomMil = disMil1(generador);
            randomMil2 = disMil2(generador);
            randomCien = disCien(generador);
            randomCincuenta = disCincuenta(generador);
            randomDiez = disDiez(generador);
            if(primeraPersona == nullptr)
                primeraPersona = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                                 infoPersona->listaNombres[randomMil],
                                                 infoPersona->listaApellidos[randomMil2],
                                                 infoPersona->listaPaises[randomCien][0],
                                                 infoPersona->listaPaises[randomCien][1],
                                                 infoPersona->listaCreencias[randomDiez],
                                                 infoPersona->listaProfesiones[randomCincuenta]);
            else if(primeraPersona->siguiente == nullptr){
                //Este caso solo se va a dar una vez y es cuándo se inserta el  segundo nodo
                if(primeraPersona->id > infoPersona->randomsUnicos[idInicial]){
                    //Significa que el que voy a insertar va a la izquierda
                    tmpInsertar = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                            infoPersona->listaNombres[randomMil],
                            infoPersona->listaApellidos[randomMil2],
                            infoPersona->listaPaises[randomCien][0],
                            infoPersona->listaPaises[randomCien][1],
                            infoPersona->listaCreencias[randomDiez],
                            infoPersona->listaProfesiones[randomCincuenta]);
                    tmpInsertar->siguiente = primeraPersona;

                    primeraPersona = tmpInsertar;
                }
                else{
                    //Debo insertar a la derecha
                    tmpInsertar = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                            infoPersona->listaNombres[randomMil],
                            infoPersona->listaApellidos[randomMil2],
                            infoPersona->listaPaises[randomCien][0],
                            infoPersona->listaPaises[randomCien][1],
                            infoPersona->listaCreencias[randomDiez],
                            infoPersona->listaProfesiones[randomCincuenta]);
                    primeraPersona->siguiente = tmpInsertar;

                }
            }
            else{//3 o más nodos
                tmpAnterior = nullptr;
                tmp = primeraPersona;
                hayInsertar = true;
                while (tmp->siguiente != nullptr){
                    if(tmp->id > infoPersona->randomsUnicos[idInicial]){
                        //Debo insertar a la izquierda de tmp
                        if(tmpAnterior == nullptr){
                            //Nuevo primer lugar
                            tmpInsertar = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                    infoPersona->listaNombres[randomMil],
                                    infoPersona->listaApellidos[randomMil2],
                                    infoPersona->listaPaises[randomCien][0],
                                    infoPersona->listaPaises[randomCien][1],
                                    infoPersona->listaCreencias[randomDiez],
                                    infoPersona->listaProfesiones[randomCincuenta]);
                            tmpInsertar->siguiente = primeraPersona;
                            primeraPersona = tmpInsertar;
                            hayInsertar = false;
                            break;//Ya inserté
                        }
                        else{//Funciona
                            tmpAnterior->siguiente = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                                    infoPersona->listaNombres[randomMil],
                                    infoPersona->listaApellidos[randomMil2],
                                    infoPersona->listaPaises[randomCien][0],
                                    infoPersona->listaPaises[randomCien][1],
                                    infoPersona->listaCreencias[randomDiez],
                                    infoPersona->listaProfesiones[randomCincuenta]);
                            tmpAnterior->siguiente->siguiente = tmp;
                            hayInsertar = false;
                            break;//Ya inserté
                        }

                    }
                    tmpAnterior = tmp;
                    tmp = tmp->siguiente;
                }

                if(hayInsertar){
                    //Si llega acá es porque va a insertar al final
                    tmp->siguiente = new NodoPersona(infoPersona->randomsUnicos[idInicial++],
                            infoPersona->listaNombres[randomMil],
                            infoPersona->listaApellidos[randomMil2],
                            infoPersona->listaPaises[randomCien][0],
                            infoPersona->listaPaises[randomCien][1],
                            infoPersona->listaCreencias[randomDiez],
                            infoPersona->listaProfesiones[randomCincuenta]);

                }

            }//Fin del else que inserta de la segunda en adelante
        }//Fin del For
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
            qDebug()<<"Generando pecados";
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
        if(i == posicion){
            existe = true;
            break;
        }
        if (tmp->siguiente == nullptr)
            break;
        tmp = tmp->siguiente;
    }
    if(existe)
        return tmp;
    else
        return nullptr;
}
void borrarListaID(unsigned int ID){
    NodoPersona * recorreNodos = primeraPersona;
    while(recorreNodos != NULL && recorreNodos->siguiente != NULL && recorreNodos->siguiente->id != ID){
    recorreNodos = recorreNodos->siguiente;
    }
    if(recorreNodos != NULL){
        if(recorreNodos->siguiente != NULL){
            NodoPersona * nodoBorrar = recorreNodos->siguiente;
            recorreNodos->siguiente = recorreNodos->siguiente->siguiente;
            delete nodoBorrar;
        }
    }
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

    //El limitador sirve para encontrar al que sigue y no encontrar siempre al primero
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

    NodoPersona* buscarPersonaID (unsigned int id){
        NodoPersona* tmp = primeraPersona;

        while (tmp != nullptr){
            if(tmp->id == id)
                return tmp;

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
                posibleHijo = arbolApellidos->obtenerHijo(arbolApellidos->raiz, personaActual, true);//La persona actual es a quien quiero agregar hijos
                if (posibleHijo != nullptr){
                    personaActual->listaHijos[i] = posibleHijo;
                    //Le asigno padre
                    posibleHijo->padre = personaActual;//Personas con mismos padres no pueden ser padres entre ellas. [Uno de los hermanos sea padre del otro hermano]
                }
                else
                    break;
            }

            personaActual = personaActual->siguiente;
        }

    }

    NodoPersona* eliminarPersona(unsigned int id){

        if (primeraPersona != nullptr){
            NodoPersona* tmp = primeraPersona;
            NodoPersona* tmpAnterior = nullptr;
            while (tmp->siguiente!= nullptr){
                if (tmp->id == id){
                    //Debo eliminar
                    if (tmpAnterior == nullptr){
                        //Significa que es la primera persona
                        tmp->siguiente = nullptr;
                        return tmp;
                    }
                    if(tmp->siguiente == nullptr){
                        //Es el último
                        tmpAnterior->siguiente = nullptr;
                        return tmp;
                    }
                    //Está en la mitad
                    tmpAnterior->siguiente = tmp->siguiente;
                    tmp->siguiente = nullptr;
                    return tmp;
                }
            }
        }
        return nullptr;

    }

};
/**
 * @brief The node struct
 * Programado por Nikolai Ershov
 * http://kukuruku.co/hub/cpp/avl-trees
 */
struct node
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) { key = k; left = right = 0; height = 1; }
};

struct arbolAVL{

    node* raiz;

    arbolAVL(){
        raiz = nullptr;
    }

    //Metodos
    unsigned char height(node* p)
    {
        return p?p->height:0;
    }

    int bfactor(node* p)
    {
        return height(p->right)-height(p->left);
    }

    void fixheight(node* p)
    {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);
        p->height = (hl>hr?hl:hr)+1;
    }

    node* rotateright(node* p)
    {
        node* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }

    node* rotateleft(node* q)
    {
        node* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }

    node* balance(node* p) // balancing the p node
    {
        fixheight(p);
        if( bfactor(p)==2 )
        {
            if( bfactor(p->right) < 0 )
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p; // balancing is not required
    }

    node* insertar (int k){
        return insert(raiz, k);
    }

    node* insert(node* p, int k) // insert k key in a tree with p root
    {
        if( !p ) return new node(k);
        if( k<p->key )
            p->left = insert(p->left,k);
        else
            p->right = insert(p->right,k);
        return balance(p);
    }

    node* findmin(node* p) // find a node with minimal key in a p tree
    {
        return p->left?findmin(p->left):p;
    }

    node* removemin(node* p) // deleting a node with minimal key from a p tree
    {
        if( p->left==0 )
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }

    node* remover (int k){
        return remove(raiz, k);
    }

    node* remove(node* p, int k) // deleting k key from p tree
    {
        if( !p ) return 0;
        if( k < p->key )
            p->left = remove(p->left,k);
        else if( k > p->key )
            p->right = remove(p->right,k);
        else //  k == p->key
        {
            node* q = p->left;
            node* r = p->right;
            delete p;
            if( !r ) return q;
            node* min = findmin(raiz);
            min->right = removemin(raiz);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }
};


//PARAÍSO
struct NodoPersonaAVL
{
    unsigned int key;
    unsigned char height;
    NodoPersonaAVL* left;
    NodoPersonaAVL* right;
    //La persona
    NodoPersona* persona;
    //Constructor
    NodoPersonaAVL(int k){
        key = k;
        left = right = 0;
        height = 1;
    }
    NodoPersonaAVL(NodoPersona* _persona){
        persona = _persona;
        key = _persona->id;
        left = right = 0;
        height = 1;
    }

};

struct ArbolPersonasAVL{

    NodoPersonaAVL* raiz;

    ArbolPersonasAVL(){
        raiz = nullptr;
    }

    //Metodos
    /**
     * @brief height
     * @param p
     * @return
     */
    unsigned char height(NodoPersonaAVL* p)
    {
        return p?p->height:0;
    }

    /**
     * @brief bfactor
     * @param p
     * @return
     */
    int bfactor(NodoPersonaAVL* p)
    {
        return height(p->right)-height(p->left);
    }
    /**
     * @brief fixheight
     * @param p
     */
    void fixheight(NodoPersonaAVL* p)
    {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);
        p->height = (hl>hr?hl:hr)+1;
    }
    /**
     * @brief rotateright
     * @param p
     * @return
     */
    NodoPersonaAVL* rotateright(NodoPersonaAVL* p)
    {
        NodoPersonaAVL* q = p->left;
        p->left = q->right;
        q->right = p;
        fixheight(p);
        fixheight(q);
        return q;
    }
    /**
     * @brief rotateleft
     * @param q
     * @return
     */
    NodoPersonaAVL* rotateleft(NodoPersonaAVL* q)
    {
        NodoPersonaAVL* p = q->right;
        q->right = p->left;
        p->left = q;
        fixheight(q);
        fixheight(p);
        return p;
    }
    /**
     * @brief balance
     * @param p
     * @return
     */
    NodoPersonaAVL* balance(NodoPersonaAVL* p) // balancing the p node
    {
        fixheight(p);
        if( bfactor(p)==2 )
        {
            if( bfactor(p->right) < 0 )
                p->right = rotateright(p->right);
            return rotateleft(p);
        }
        if( bfactor(p)==-2 )
        {
            if( bfactor(p->left) > 0  )
                p->left = rotateleft(p->left);
            return rotateright(p);
        }
        return p; // balancing is not required
    }
    /**
     * @brief insertar
     * AUXILIAR
     * @param k
     * @return
     */
    NodoPersonaAVL* insertar (NodoPersona* persona){
        return insert(raiz, persona);
    }
    /**
     * @brief insert
     * @param p
     * @param k
     * @return
     */
    NodoPersonaAVL* insert(NodoPersonaAVL* p, NodoPersona* persona) // insert k key in a tree with p root
    {
        if( !p )
            return new NodoPersonaAVL(persona);
        if( persona->id < p->key )
            p->left = insert(p->left,persona);
        else
            p->right = insert(p->right,persona);
        return balance(p);
    }
    /**
     * @brief findmin
     * @param p
     * @return
     */
    NodoPersonaAVL* findmin(NodoPersonaAVL* p) // find a node with minimal key in a p tree
    {
        return p->left?findmin(p->left):p;
    }
    /**
     * @brief removemin
     * @param p
     * @return
     */
    NodoPersonaAVL* removemin(NodoPersonaAVL* p) // deleting a node with minimal key from a p tree
    {
        if( p->left==0 )
            return p->right;
        p->left = removemin(p->left);
        return balance(p);
    }
    /**
     * @brief remover
     * AUXILIAR
     * @param k
     * @return
     */
    NodoPersonaAVL* remover (int k){
        return remove(raiz, k);
    }
    /**
     * @brief remove
     * @param p
     * @param k
     * @return
     */
    NodoPersonaAVL* remove(NodoPersonaAVL* p, unsigned int k) // deleting k key from p tree
    {
        if( !p ) return 0;
        if( k < p->key )
            p->left = remove(p->left,k);
        else if( k > p->key )
            p->right = remove(p->right,k);
        else //  k == p->key
        {
            NodoPersonaAVL* q = p->left;
            NodoPersonaAVL* r = p->right;
            delete p;
            if( !r ) return q;
            NodoPersonaAVL* min = findmin(raiz);
            min->right = removemin(raiz);
            min->left = q;
            return balance(min);
        }
        return balance(p);
    }
    //Método exclusivo para el arbol mundo
    void insertarMundo (ListaPersonas* listaMundo){
        //Primero debo conocer que potencia de 2 debo utilizar
        int potencia2 = 1;
        int corte = listaMundo->largo()/potencia2;
        int porcentaje1 = listaMundo->largo() * 0.01;
        while (porcentaje1/potencia2 > 1){
            potencia2 = potencia2 * 2;
        }
        corte = listaMundo->largo()/potencia2;
        int desplazamiento = 0;
        //Como tengo la potencia de dos exacta voy a utilizar esta para realizar el corte
        for (int i = 0; i < potencia2-1; i++){//La potencia me indica la cantidad de nodos a insertar, pero hay que restarle 1
            raiz = insertar(listaMundo->buscarPersonaPos(desplazamiento));
            desplazamiento += corte;

        }
    }

};

typedef struct NodoSplay{
    int dato;
    NodoPersona * candidatoInfierno;
    NodoSplay* lchild;
    NodoSplay* rchild;

    NodoSplay(NodoPersona * candidato){
        this->dato = candidato->id;
        this->candidatoInfierno = candidato;
        this->lchild = NULL;
        this->rchild = NULL;
    }

    NodoSplay(){
        this->dato = -1;
        this->lchild = this->rchild = NULL;
    }

}NodoSplay;



typedef struct Splay{

    NodoSplay * raiz;

    Splay(){
        this->raiz = NULL;
    }

    void insertarNodo(NodoPersona * candidato){
        if(candidato != NULL)
            this->raiz = this->Insert(candidato->id,this->raiz,candidato);
    }

    void borrarNodo(int dato){
        this->raiz = this->Delete(dato,this->raiz);
    }

    // RR(Y rotates to the right)
    NodoSplay* RR_Rotate(NodoSplay* k2){
        NodoSplay* k1 = k2->lchild;
        k2->lchild = k1->rchild;
        k1->rchild = k2;
        return k1;
    }

    // LL(Y rotates to the left)
    NodoSplay* LL_Rotate(NodoSplay* k2){
        NodoSplay* k1 = k2->rchild;
        k2->rchild = k1->lchild;
        k1->lchild = k2;
        return k1;
    }

    // An implementation of top-down splay tree
    NodoSplay * manipularArbol(int dato, NodoSplay* root){
        if (!root)
            return NULL;
        NodoSplay * header = new NodoSplay();
        /* header.rchild points to L tree;
        header->lchild points to R Tree */
        header->lchild = header->rchild = NULL;
        NodoSplay* LeftTreeMax = header;
        NodoSplay* RightTreeMin = header;
        while (1)
        {
            if (dato < root->dato)
            {
                if (!root->lchild)
                    break;
                if (dato < root->lchild->dato)
                {
                    root = RR_Rotate(root);
                    // only zig-zig mode need to rotate once,
                    if (!root->lchild)
                        break;
                }
                /* Link to R Tree */
                RightTreeMin->lchild = root;
                RightTreeMin = RightTreeMin->lchild;
                root = root->lchild;
                RightTreeMin->lchild = NULL;
            }
            else if (dato > root->dato)
            {
                if (!root->rchild)
                    break;
                if (dato > root->rchild->dato)
                {
                    root = LL_Rotate(root);
                    // only zag-zag mode need to rotate once,
                    if (!root->rchild)
                        break;
                }
                /* Link to L Tree */
                LeftTreeMax->rchild = root;
                LeftTreeMax = LeftTreeMax->rchild;
                root = root->rchild;
                LeftTreeMax->rchild = NULL;
            }
            else
                break;
        }
        /* assemble L Tree, Middle Tree and R tree */
        LeftTreeMax->rchild = root->lchild;
        RightTreeMin->lchild = root->rchild;
        root->lchild = header->rchild;
        root->rchild = header->lchild;
        return root;
    }

    NodoSplay* Insert(int dato, NodoSplay * root,NodoPersona * candidato){

        static NodoSplay * p_node = NULL;
        if (!p_node)
            p_node = new NodoSplay(candidato);
        else{
            p_node->dato = dato;
            p_node->candidatoInfierno = candidato;
        }
        if (!root){
            root = p_node;
            p_node = NULL;
            return root;
        }
        root = manipularArbol(dato, root);
        /* This is BsplayPrueba that, all datos <= root->dato is in root->lchild, all datos >
        root->dato is in root->rchild. */
        if (dato < root->dato){
            p_node->lchild = root->lchild;
            p_node->rchild = root;
            root->lchild = NULL;
            root = p_node;
        }
        else if (dato > root->dato){
            p_node->rchild = root->rchild;
            p_node->lchild = root;
            root->rchild = NULL;
            root = p_node;
        }
        else
            return root;
        p_node = NULL;
        return root;
    }

    NodoSplay * Delete(int dato, NodoSplay* root)
    {
        NodoSplay* temp;
        if (!root)
            return NULL;
        root = manipularArbol(dato, root);
        if (dato != root->dato)
            return root;
        else
        {
            if (!root->lchild)
            {
                temp = root;
                root = root->rchild;
            }
            else
            {
                temp = root;
                /*Note: Since dato == root->dato,
                so after Splay(dato, root->lchild),
                the tree we get will have no right child tree.*/
                root = manipularArbol(dato, root->lchild);
                root->rchild = temp->rchild;
            }
            free(temp);
            return root;
        }
    }

    NodoSplay * Search(int dato, NodoSplay* root)
    {
        return manipularArbol(dato, root);
    }

    void enOrden(){
        InOrder(this->raiz);
    }

    void InOrder(NodoSplay * root){
        if (root){
            InOrder(root->lchild);
            qDebug()<< "dato: " <<root->dato;
            if(root->lchild)
                qDebug()<< " | left child: "<< root->lchild->dato;
            if(root->rchild)
                qDebug() << " | right child: " << root->rchild->dato;
            qDebug()<< "\n";
            InOrder(root->rchild);
        }
    }

    NodoSplay * buscarNodo(int dato){
        return this->Search(dato,this->raiz);
    }

}Splay;

struct Infierno{
    Splay * splayBusqueda;

    Infierno(){
        this->splayBusqueda = NULL;
    }

    Splay * getSplayInfierno(){
        return this->splayBusqueda;
    }


    //--------------------------------------------------------------------
    //Inicio del Heap
    //--------------------------------------------------------------------
void convertirAMaxHeap(int arreglo[], int i, int n){
    int j, temp;
    temp = arreglo[i];
    j = 2 * i;
    while (j <= n)
    {
        if (j < n && arreglo[j+1] > arreglo[j])
            j = j + 1;
        if (temp > arreglo[j])
            break;
        else if (temp <= arreglo[j])
        {
            arreglo[j / 2] = arreglo[j];
            j = 2 * j;
        }
    }
    arreglo[j/2] = temp;
    return;
}

void crearMaxHeap(int arreglo[],int n){
    int i;
    for(i = n/2; i >= 1; i--)
    {
        convertirAMaxHeap(arreglo,i,n);
    }
}
/**
    void imprimirHeap(int listaHeap[]){
        qDebug()<<"Max Heap\n";
        for(unsigned int i = 1; i <= (sizeof(listaHeap)/sizeof(listaHeap[0]));i++){
            qDebug() <<listaHeap[i];
        }
    }
*/
    //--------------------------------------------------------------------
    //Fin del Heap
    //---
};




#endif // ESTRUCTURAS_H
