#include "Clientes.h"

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

bool ListaClientes::validarCodigo(QString pCodigo){
    static QRegularExpression re("^\\d{3}$");
    QRegularExpressionMatch match = re.match(pCodigo);
    return match.hasMatch();
}

bool ListaClientes::validarPrioridad(QString pPrioridad){
    static QRegularExpression re("^([1-9]|10){1}$");
    QRegularExpressionMatch match = re.match(pPrioridad);
    return match.hasMatch();
}
