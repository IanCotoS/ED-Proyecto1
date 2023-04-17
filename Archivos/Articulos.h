#ifndef ARTICULOS_H
#define ARTICULOS_H

#include "LibreriasBasicas.h"

#endif // ARTICULOS_H

// Declaración de structs
struct Articulo;
struct NodoArticulo;
struct ListaArticulos;

// Structs
// Struct Articulo
struct Articulo{

    // Miembros
    QString codigo;
    int cantidadAlmacen;
    int tiempoFabricacionSegundos;
    QString categoria;
    QString ubicacionBodega;

    // Constructor
    Articulo(QString pCodigo, int pCantidadAlmacen, int pTiempoFabricacionSegundos,
             QString pCategoria, QString pUbicacionBodega){
        codigo = pCodigo;
        cantidadAlmacen = pCantidadAlmacen;
        tiempoFabricacionSegundos = pTiempoFabricacionSegundos;
        categoria = pCategoria;
        ubicacionBodega = pUbicacionBodega;
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct Articulo

// Struct NodoArticulo
struct NodoArticulo{

    // Miembros
    Articulo * articulo;
    NodoArticulo * siguiente;
    NodoArticulo * anterior;

    // Constructores
    NodoArticulo(){
        articulo = NULL;
        siguiente = anterior = NULL;
    }

    NodoArticulo(Articulo * pArticulo) {
        articulo = pArticulo; // asigna los datos
        siguiente = anterior = NULL; // sig es null
    }

    NodoArticulo(QString pCodigo, int pCantidadAlmacen, int pTiempoFabricacion,
                 QString pCategoria, QString pUbicacionBodega){
        siguiente = anterior = NULL;
        articulo = new Articulo(pCodigo, pCantidadAlmacen, pTiempoFabricacion,
                               pCategoria, pUbicacionBodega);
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct NodoArticulo

// Struct ListaArticulos
struct ListaArticulos{

    // Miembros
    NodoArticulo * primerNodo, * ultimoNodo;

    // Constructor
    ListaArticulos(){
        primerNodo = ultimoNodo = NULL;
    }

    // Encabezado de funciones
    void insertarAlInicio(Articulo *);
    void insertarAlFinal(Articulo *);
    void limpiarMemoria();
    int largo();
    QString devuelveInfo();
    bool existeCodigo(QString);
    bool validarDatos(QString, QString, QString, QString, QString);
    bool cargarEnMemoria();
}; // Fin Struct ListaArticulos
