#include "Articulos.h"

// Variables
// Expresiones regulares
QRegularExpression reCodigoArticulo("^[A-Z]\\d{2}$");
QRegularExpression reCantidadEnAlmacen("^\\d+$");
QRegularExpression reTiempoFabricacionSeg("^([1-9]\\d+|[1-9])$");
QRegularExpression reCategoria("^(A|B|C)$");
QRegularExpression reUbicacionBodega("^[A-Z](0[1-9]|10){1}$");

// Métodos Articulo
QString Articulo::devuelveInfo(){
    return ("\nCódigo " + codigo + "\nCantidad en almacen: " + QString::number(cantidadAlmacen) +
            "\nTiempo de fabricación (segundos): " + QString::number(tiempoFabricacionSegundos) +
            "\nCategoría: " + categoria + "\nUbicación: " + ubicacionBodega);
}

// Métodos NodoArticulo
QString NodoArticulo::devuelveInfo(){
    return (articulo->devuelveInfo());
}

// Métodos ListaArticulos
void ListaArticulos::insertarAlInicio(Articulo * pArticulo){
    if (primerNodo == NULL){
        primerNodo = new NodoArticulo(pArticulo);
        ultimoNodo = primerNodo;
    }
    else{
        NodoArticulo * nuevo = new NodoArticulo(pArticulo);
        nuevo->siguiente = primerNodo;
        primerNodo ->anterior = nuevo;
        primerNodo = nuevo;
    }
}

void ListaArticulos::insertarAlFinal(Articulo * pArticulo){
    if (primerNodo == NULL){
        primerNodo = new NodoArticulo(pArticulo);
        ultimoNodo = primerNodo;
    }
    else{
        NodoArticulo *nuevo = new NodoArticulo(pArticulo);
        ultimoNodo->siguiente = nuevo;
        nuevo->anterior = ultimoNodo;
        ultimoNodo = nuevo;
    }
}

int ListaArticulos::largo(){
    int i = 0;
    NodoArticulo * temp = primerNodo;
    while (temp!=NULL){
        i++;
        temp = temp->siguiente;
    }
    return i;
}

QString ListaArticulos::devuelveInfo(){
    NodoArticulo * tmp = primerNodo;
    QString info = "";
    while(tmp != NULL){
        info += tmp->devuelveInfo();
        tmp = tmp->siguiente;
    }
    delete tmp;
    return (info + "\n");
}

bool ListaArticulos::existeCodigo(QString pCodigo){
    NodoArticulo * tmp = primerNodo;
    while(tmp != NULL){
        if (tmp->articulo->codigo == pCodigo){
            qCritical() << "El código del artículo " + pCodigo + " ya se encuentra en la lista de artículos.";
            return true;
        }
        tmp = tmp->siguiente;
    }
    return false;
}

void ListaArticulos::limpiarMemoria(){
    NodoArticulo * tmp = primerNodo;
    NodoArticulo * sig;
    while (tmp != NULL) {
        sig = tmp->siguiente;
        delete tmp;
        tmp = sig;
    }
    primerNodo = NULL;
    delete this; // Se elimina en memoria todo
}

bool ListaArticulos::validarDatos(QString pCodigo, QString pCantidadAlmacen, QString pTiempoFabricacionSegundos,
                  QString pCategoria, QString pUbicacionBodega){
    if (!validarFormato(pCodigo, reCodigoArticulo)){
        qCritical() << "El código del artículo " + pCodigo + " cuenta con un formato incorrecto.";
        return false;
    }
    else if(!validarFormato(pCantidadAlmacen, reCantidadEnAlmacen)){
        qCritical() << "La cantidad en almacén debe ser 0 o mayor (" << pCantidadAlmacen << ").";
        return false;
    }
    else if (!validarFormato(pTiempoFabricacionSegundos, reTiempoFabricacionSeg)){
        qCritical() << "El tiempo de fabricación debe ser mayor a 0 (" << pTiempoFabricacionSegundos << ").";
        return false;
    }
    else if (!validarFormato(pCategoria, reCategoria)){
        qCritical() << "La categoria debe ser A, B o C (" << pCategoria << ").";
        return false;
    }
    else if (!validarFormato(pUbicacionBodega, reUbicacionBodega)){
        qCritical() << "La ubicación en bodega debe ser una letra mayúscula," <<
                       "seguido de un número del 01 al 10 (" << pUbicacionBodega << ").";
        return false;
    }
    return true;
}

bool ListaArticulos::cargarEnMemoria(){
    QString str = retornarTextoArchivo("C:\\Users\\sotic\\"
                                       "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaArticulos.txt");
    QStringList list = separaAtributos(str);
    for (int i = 0; i < list.length(); i+=5){
        if (!validarDatos(list.at(i), list.at(i+1), list.at(i+2), list.at(i+3), list.at(i+4)) || existeCodigo(list.at(i))){
            qCritical() << "Error en la línea" << largo()+1 << "en el archivo de los artículos";
            limpiarMemoria();
            return false;
        }
        this->insertarAlFinal(new Articulo(list.at(i), list.at(i+1).toInt(), list.at(i+2).toInt(),
                                           list.at(i+3), list.at(i+4)));
    }
    return true;
}
