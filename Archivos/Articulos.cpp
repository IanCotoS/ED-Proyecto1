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
    delete tmp;
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
    static QRegularExpression re("^([1-9]\\d+|[1-9])$");
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
    if(validarCodigo(pCodigo) && validarCantidad(pCantidadAlmacen) &&
          validarTiempo(pTiempoFabricacionSegundos) && validarCategoria(pCategoria) &&
          validarUbicacion(pUbicacionBodega))
        return true;
    return false;
}

QStringList ListaArticulos::separaAtributos(QString str){ // Puede meterse en otro archivo,
    // ya que se ocupa en más structs
    static QRegularExpression re("\\s+");
    return str.split(re);
}

bool ListaArticulos::cargarEnMemoria(){
    QString str = retornarTextoArchivo("C:\\Users\\sotic\\"
                                       "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaArticulos.txt");
    QStringList list = separaAtributos(str);
    for (int i = 0; i < list.length(); i+=5){
        if (!validarDatos(list.at(i), list.at(i+1), list.at(i+2), list.at(i+3), list.at(i+4)) || existeCodigo(list.at(i))){
            limpiarMemoria();
            return false;
        }
        this->insertarAlFinal(new Articulo(list.at(i), list.at(i+1).toInt(), list.at(i+2).toInt(),
                                           list.at(i+3), list.at(i+4)));
    }
    return true;
}
