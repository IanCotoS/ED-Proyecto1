#include "Clientes.h"

// Variables
// Expresiones regulares
QRegularExpression reCodigoCliente("^\\d{3}$");
QRegularExpression rePrioridad("^([1-9]|10){1}$");

// Funciones Cliente
QString Cliente::devuelveInfo(){
    return "\r\nCliente " + codigo + "\r\nNombre: " + nombre + "\r\nPrioridad: " +  QString::number(prioridad);
}

// Funciones NodoCliente
QString NodoCliente::devuelveInfo(){
    return cliente->devuelveInfo();
}

// Funciones ListaCliente
void ListaClientes::insertarAlInicio(Cliente * pCliente){
    if (primerNodo == NULL){
        primerNodo = new NodoCliente(pCliente);
    }
    else{
        NodoCliente * nuevo = new NodoCliente(pCliente);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaClientes::insertarAlFinal(Cliente * pCliente){
    if (primerNodo == NULL){
        primerNodo = new NodoCliente(pCliente);
    }
    else{
        NodoCliente * tmp = primerNodo;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        NodoCliente * nuevo = new NodoCliente(pCliente);
        tmp->siguiente = nuevo;
    }
}

void ListaClientes::limpiarMemoria(){
    NodoCliente * tmp = primerNodo;
    NodoCliente * sig;
    while (tmp != NULL) {
        sig = tmp->siguiente;
        delete tmp;
        tmp = sig;
    }
    primerNodo = NULL;
    delete this; // Se elimina en memoria todo
}

QString ListaClientes::devuelveInfo(){
    NodoCliente * tmp = primerNodo;
    QString info = "";
    while(tmp != NULL){
        info += tmp->devuelveInfo();
        tmp = tmp->siguiente;
    }
    return (info + "\r\n");
}

int ListaClientes::largo(){
    NodoCliente * tmp = primerNodo;
    int cant = 0;
    while(tmp != NULL){
        cant++;
        tmp = tmp->siguiente;
    }
    return cant;
}

Cliente * ListaClientes::devuelveCliente(QString pCodigo){
    NodoCliente * tmp = primerNodo;
    while(tmp != NULL){
        if (tmp->cliente->codigo == pCodigo){
            return tmp->cliente;
        }
        tmp = tmp->siguiente;
    }
    return NULL;
}

bool ListaClientes::validarDatos(QString pCodigo, QString pPrioridad){
    if (!validarFormato(pCodigo, reCodigoCliente)){
        qCritical() << "El código del cliente " + pCodigo + " cuenta con un formato incorrecto.";
        return false;
    }
    else if (!validarFormato(pPrioridad, rePrioridad)){
        qCritical() << "La prioridad de los clientes debe ser un número entre 1 y 10 (" <<
                    pPrioridad << ")";
        return false;
    }
    return true;
}

bool ListaClientes::cargarEnMemoria(){
    QString str = retornarTextoArchivo("ArchivosDeTexto\\Clientes.txt");
    QStringList list = separaAtributos(str);
    for (int i = 0; i < list.length(); i+=3){
        if (!validarDatos(list.at(i), list.at(i+2))){
            qCritical() << "Error en la línea" << largo()+1 << "en el archivo de los clientes";
            limpiarMemoria();
            return false; // Luego, en la simulación, se debe evaluar si no es null para seguir
        }
        else if (devuelveCliente(list.at(i)) != NULL){
            qCritical() << "El código " + list.at(i) + " ya se encuentra en la lista de clientes.";
            limpiarMemoria();
            return false;
        }
        this->insertarAlFinal(new Cliente(list.at(i), list.at(i+1), list.at(i+2).toInt()));
    }
    return true;
}
