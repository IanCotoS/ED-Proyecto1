#ifndef CLIENTES_H
#define CLIENTES_H

#include "LibreriasBasicas.h"

#endif // CLIENTES_H

struct Cliente{

    // Miembros
    QString codigo;
    QString nombre;
    int prioridad;

    // Constructor
    Cliente(QString pCodigo, QString pNombre, int pPrioridad){
        codigo = pCodigo;
        nombre = pNombre;
        prioridad = pPrioridad;
    }

    // Encabezado de funciones
    QString devuelveInfo();
};

struct NodoCliente{

    // Miembros
    Cliente * cliente; // Dato
    NodoCliente * siguiente; // Puntero para enlazar nodos

    // Constructor
    NodoCliente(Cliente * pCliente){
        cliente = pCliente;
        siguiente = NULL; // sig es null
    }

    // Encabezado de funciones
    QString devuelveInfo();
};

struct ListaClientes{

    // Miembros
    NodoCliente * primerNodo;

    // Constructor
    ListaClientes(){
        primerNodo = NULL;
    }

    // Encabezado de funciones
    void insertarAlInicio(Cliente *);
    void insertarAlFinal(Cliente *);
    QString devuelveInfo();
    int largo();
    bool existeCodigo(QString);
    bool validarCodigo(QString);
    bool validarPrioridad(QString);
};
