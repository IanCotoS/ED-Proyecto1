#ifndef CLIENTES_H
#define CLIENTES_H

#include "LibreriasBasicas.h"

#endif // CLIENTES_H

struct Cliente{

    // Miembros
    string codigo;
    string nombre;
    int prioridad;

    // Constructor
    Cliente(string pCodigo, string pNombre, int pPrioridad){
        codigo = pCodigo;
        nombre = pNombre;
        prioridad = pPrioridad;
    }

    // Encabezado de funciones
    void imprimir(void);
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
    void imprimir(void);
};

struct ColaCliente{

    // Miembros
    NodoCliente * frente;

    // Constructor
    ColaCliente(){
        frente = NULL;
    }

    // Encabezados de funciones
    bool vacia(void);
    NodoCliente * verFrente(void);
    void encolarPersona(Cliente * pCliente);
    NodoCliente * desencolar (void);
    void imprimir(void);
};
