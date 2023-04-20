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
    int cantidad;
    int tiempoFabricacionSegundos;
    QString categoria;
    QString ubicacionBodega;
    int cantidadReal;

    // Constructor
    Articulo(QString pCodigo, int pCantidad , int pTiempoFabricacionSegundos,
             QString pCategoria, QString pUbicacionBodega){
        codigo = pCodigo;
        cantidad = pCantidad ;
        tiempoFabricacionSegundos = pTiempoFabricacionSegundos;
        categoria = pCategoria;
        ubicacionBodega = pUbicacionBodega;
        cantidadReal = pCantidad;
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
                 QString pCategoria, QString pUbicacionBodega, int pCantidadReal){
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
    Articulo * devuelveArticulo(QString);
    bool validarDatos(QString, QString, QString, QString, QString);
    bool cargarEnMemoria();
}; // Fin Struct ListaArticulos
