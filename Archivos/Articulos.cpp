#include "Articulos.h"

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
    return (info + "\n");
}

bool ListaArticulos::existeCodigo(QString pCodigo){
    NodoArticulo * tmp = primerNodo;
    while(tmp != NULL){
        if (tmp->articulo->codigo == pCodigo)
            return true;
        tmp = tmp->siguiente;
    }
    return false;
}

bool ListaArticulos::validarCodigo(QString pCodigo){
    static QRegularExpression re("^[A-Z]\\d{2}$");
    QRegularExpressionMatch match = re.match(pCodigo);
    return match.hasMatch();
}

bool ListaArticulos::validarCantidad(QString pCantidad){
    static QRegularExpression re("^\\d+$");
    QRegularExpressionMatch match = re.match(pCantidad);
    return match.hasMatch();
}

bool ListaArticulos::validarTiempo(QString pTiempo){
    static QRegularExpression re("^[1-9](\\d+)$");
    QRegularExpressionMatch match = re.match(pTiempo);
    return match.hasMatch();
}

bool ListaArticulos::validarCategoria(QString pCategoria){
    static QRegularExpression re("^(A|B|C)$");
    QRegularExpressionMatch match = re.match(pCategoria);
    return match.hasMatch();
}

bool ListaArticulos::validarUbicacion(QString pUbicacion){
    static QRegularExpression re("^[A-Z](0[1-9]|10){1}$");
    QRegularExpressionMatch match = re.match(pUbicacion);
    return match.hasMatch();
}
