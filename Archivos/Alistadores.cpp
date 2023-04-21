#include "Alistadores.h"

// Funciones Alistador
QString Alistador::devuelveInfo(){
    return "\r\nCliente " + codigo + "\r\nNombre: " + nombre + "\r\nPrioridad: " +  QString::number(prioridad);
}

// Funciones NodoAlistador
QString NodoAlistador::devuelveInfo(){
    return cliente->devuelveInfo();
}

// Funciones ListaAlistadores
void ListaAlistadores::insertarAlFinal(Cliente * pCliente){
    if (primerNodo == NULL){
        primerNodo = new NodoAlistador(pCliente);
    }
    else{
        NodoAlistador * tmp = primerNodo;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        NodoAlistador * nuevo = new NodoAlistador(pCliente);
        tmp->siguiente = nuevo;
    }
}

QString ListaAlistadores::devuelveInfo(){
    NodoAlistador * tmp = primerNodo;
    QString info = "";
    while(tmp != NULL){
        info += tmp->devuelveInfo();
        tmp = tmp->siguiente;
    }
    return (info + "\r\n");
}

Alistador * ListaAlistadores::alistadorInactivo(){
    NodoAlistador * tmp = primerNodo;
    while(tmp != NULL){
        if (tmp->alistador->activo == false){
            return tmp->alistador;
        }
        tmp = tmp->siguiente;
    }
    return NULL;
}

