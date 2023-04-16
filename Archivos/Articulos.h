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
    int largo();
    QString devuelveInfo();
    bool existeCodigo(QString);
    bool validarCodigo(QString);
    bool validarCantidad(QString);
    bool validarTiempo(QString);
    bool validarCategoria(QString);
    bool validarUbicacion(QString);

    void limpiarMemoria(){
        NodoArticulo * tmp = primerNodo;
        NodoArticulo * sig;
        while (tmp != NULL) {
            sig = tmp->siguiente;
            delete tmp;
            tmp = sig;
        }
        primerNodo = NULL;
    }

    bool validarDatos(QString pCodigo, QString pCantidadAlmacen, QString pTiempoFabricacionSegundos,
                      QString pCategoria, QString pUbicacionBodega){
        if(!(validarCodigo(pCodigo) && validarCantidad(pCantidadAlmacen) &&
              validarTiempo(pTiempoFabricacionSegundos) && validarCategoria(pCategoria) &&
              validarUbicacion(pUbicacionBodega)))
            return false;
        return true;
    }

    QStringList separaAtributos(QString str){ // Puede meterse en otro archivo,
        // ya que se ocupa en más structs
        static QRegularExpression re("\\s+");
        return str.split(re);
    }

    ListaArticulos * cargarEnMemoria(){
        ListaArticulos * listaArticulos = new ListaArticulos();
        QString str = retornarTextoArchivo("C:\\Users\\sotic\\"
                                           "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaArticulos.txt");
        QStringList list = separaAtributos(str);
        for (int i = 0; i < list.length(); i+=5){
            if (!validarDatos(list.at(i), list.at(i+1), list.at(i+2), list.at(i+3), list.at(i+4))){
                limpiarMemoria();
                delete listaArticulos; // Se eliminan ambas listas evitando un leak de memoria
                return NULL; // Luego, en la simulación, se debe evaluar si no es null para seguir
            }
            listaArticulos->insertarAlFinal(new Articulo(list.at(i), list.at(i+1).toInt(), list.at(i+2).toInt(),
                                                         list.at(i+3), list.at(i+4)));
        }
        return listaArticulos;
    }
}; // Fin Struct ListaArticulos
