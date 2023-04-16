#include "Clientes.h"

// Funciones Cliente
QString Cliente::devuelveInfo(){
    return "\nCliente " + codigo + "\nNombre: " + nombre + "\nPrioridad: " +  QString::number(prioridad);
}

// Funciones NodoCliente
QString NodoCliente::devuelveInfo(){
    return cliente->devuelveInfo();
}

// Funciones ListaCliente
void ListaClientes::insertarAlInicio(Cliente * pCliente){
    if (primerNodo == NULL){
        primerNodo = new NodoCliente(pCliente);
    }
    else{
        NodoCliente * nuevo = new NodoCliente(pCliente);
        nuevo->siguiente = primerNodo;
        primerNodo = nuevo;
    }
}

void ListaClientes::insertarAlFinal(Cliente * pCliente){
    if (primerNodo == NULL){
        primerNodo = new NodoCliente(pCliente);
    }
    else{
        NodoCliente * tmp = primerNodo;
        while(tmp->siguiente != NULL){
            tmp = tmp->siguiente;
        }
        NodoCliente * nuevo = new NodoCliente(pCliente);
        tmp->siguiente = nuevo;
    }
}

void ListaClientes::limpiarMemoria(){
    NodoCliente * tmp = primerNodo;
    NodoCliente * sig;
    while (tmp != NULL) {
        sig = tmp->siguiente;
        delete tmp;
        tmp = sig;
    }
    primerNodo = NULL;
}

QString ListaClientes::devuelveInfo(){
    NodoCliente * tmp = primerNodo;
    QString info = "";
    while(tmp != NULL){
        info += tmp->devuelveInfo();
        tmp = tmp->siguiente;
    }
    return (info + "\n");
}

int ListaClientes::largo(){
    NodoCliente * tmp = primerNodo;
    int cant = 0;
    while(tmp != NULL){
        cant++;
        tmp = tmp->siguiente;
    }
    return cant;
}

bool ListaClientes::existeCodigo(QString pCodigo){
    NodoCliente * tmp = primerNodo;
    while(tmp != NULL){
        if (tmp->cliente->codigo == pCodigo)
            return true;
        tmp = tmp->siguiente;
    }
    return false;
}

bool ListaClientes::validarCodigo(QString pCodigo){
    static QRegularExpression re("^\\d{3}$");
    QRegularExpressionMatch match = re.match(pCodigo);
    return match.hasMatch();
}

bool ListaClientes::validarPrioridad(QString pPrioridad){ // Puede hacerse una sola con dos parámetros,
                                                          // un QString a comprobar y la re a comparar
    static QRegularExpression re("^([1-9]|10){1}$");
    QRegularExpressionMatch match = re.match(pPrioridad);
    return match.hasMatch();
}

bool ListaClientes::validarDatos(QString pCodigo, QString pPrioridad){
    if(!(validarCodigo(pCodigo) && validarPrioridad(pPrioridad)))
        return false;
    return true;
}

QStringList * ListaClientes::separaAtributos(QString str){ // Puede meterse en otro archivo,
                                                           // ya que se ocupa en más structs
    QStringList * list = new QStringList();
    static QRegularExpression re("\\s+");
    (*list) = str.split(re);
    return list;
}

ListaClientes * ListaClientes::cargarEnMemoria(){
    ListaClientes * listaClientes = new ListaClientes();
    QString str = retornarTextoArchivo("C:\\Users\\sotic\\"
                                       "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
    QStringList * list = separaAtributos(str);
    for (int i = 0; i < list->length(); i+=3){
        if (!validarDatos(list->at(i), list->at(i+2))){
            limpiarMemoria();
            delete list;
            delete listaClientes; // Se eliminan ambas listas evitando un leak de memoria
            return NULL; // Luego, en la simulación, se debe evaluar si no es null para seguir
        }
        listaClientes->insertarAlFinal(new Cliente(list->at(i), list->at(i+1), list->at(i+2).toInt()));
    }
    delete list; // Se elimina la lista que no se ocupa
    return listaClientes;
}
