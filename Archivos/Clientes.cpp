#include "Clientes.h"

// Variables
// Expresiones regulares
QRegularExpression reCodigoCliente("^\\d{3}$");
QRegularExpression rePrioridad("^([1-9]|10){1}$");

// Funciones Cliente
QString Cliente::devuelveInfo(){
    return "\nCliente " + codigo + "\nNombre: " + nombre + "\nPrioridad: " +  QString::number(prioridad);
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
    return (info + "\n");
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

bool ListaClientes::existeCodigo(QString pCodigo){
    NodoCliente * tmp = primerNodo;
    while(tmp != NULL){
        if (tmp->cliente->codigo == pCodigo)
            return true;
        tmp = tmp->siguiente;
    }
    return false;
}

bool ListaClientes::validarDatos(QString pCodigo, QString pPrioridad){
    if(validarFormato(pCodigo, reCodigoCliente) && validarFormato(pPrioridad, rePrioridad))
        return true;
    return false;
}

bool ListaClientes::cargarEnMemoria(){
    QString str = retornarTextoArchivo("C:\\Users\\sotic\\"
                                       "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
    QStringList list = separaAtributos(str);
    for (int i = 0; i < list.length(); i+=3){
        if (!validarDatos(list.at(i), list.at(i+2)) || existeCodigo(list.at(i))){
            limpiarMemoria();
            return false; // Luego, en la simulación, se debe evaluar si no es null para seguir
        }
        this->insertarAlFinal(new Cliente(list.at(i), list.at(i+1), list.at(i+2).toInt()));
    }
    return true;
}
