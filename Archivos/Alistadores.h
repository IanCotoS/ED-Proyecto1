
#ifndef ALISTADORESH_H
#define ALISTADORESH_H

#include "LibreriasBasicas.h"

#endif // ALISTADORESH_H

// Declaraciones de structs
struct Alistador;
struct NodoAlistador;
struct ListaAlistadores;

// Structs
// Struct Alistador
struct Alistador{

    // Miembros
    int id;
    bool activo;

    // Constructor
    Alistador(int pId){
        id = pId;
        activo = false;
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct Cliente

// Struct NodoCliente
struct NodoAlistador{

    // Miembros
    Alistador * alistador;
    NodoAlistador * siguiente;

    // Constructores
    NodoAlistador(){
        alistador = NULL;
        siguiente = NULL;
    }

    NodoAlistador(Alistador * pAlistador){
        alistador = pAlistador;
        siguiente = NULL;
    }

    NodoAlistador(int pId){
        alistador = new Alistador(pId);
        siguiente = NULL;
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct NodoCliente

// Struct ListaClientes
struct ListaAlistadores{

    // Miembros
    NodoAlistador * primerNodo;

    // Constructor
    ListaAlistadores(){
        primerNodo = NULL;
        for (int id = 1; id <= 6; id++){
            insertarAlFinal(new Alistador(id));
        }
    }

    // Encabezado de funciones
    void insertarAlFinal(Alistador *);
    QString devuelveInfo();
    Alistador * alistadorInactivo();
}; // Fin Struct ListaClientes
