#ifndef CLIENTES_H
#define CLIENTES_H

#include "LibreriasBasicas.h"

#endif // CLIENTES_H

// Variables
// Expresiones regulares
QRegularExpression reCodigoCliente("^\\d{3}$");
QRegularExpression rePrioridad("^([1-9]|10){1}$");

// Declaraciones struct
struct Cliente;
struct NodoCliente;
struct ListaClientes;

// Structs
// Struct Cliente
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
}; // Fin Struct Cliente

// Struct NodoCliente
struct NodoCliente{

    // Miembros
    Cliente * cliente;
    NodoCliente * siguiente;

    // Constructores
    NodoCliente(){
        cliente = NULL;
        siguiente = NULL;
    }

    NodoCliente(Cliente * pCliente){
        cliente = pCliente;
        siguiente = NULL;
    }

    NodoCliente(QString pCodigo, QString pNombre, int pPrioridad){
        cliente = new Cliente(pCodigo, pNombre, pPrioridad);
        siguiente = NULL;
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct NodoCliente

// Struct ListaClientes
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
    void limpiarMemoria();
    QString devuelveInfo();
    int largo();
    bool existeCodigo(QString);
    bool validarDatos(QString, QString);
    bool cargarEnMemoria();
}; // Fin Struct ListaClientes
