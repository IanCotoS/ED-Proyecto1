#include "Pedidos.h"

// Variables
// Expresiones regulares
QRegularExpression reNumero("^\\d+$");

// Funciones Pedido
QString Pedido::devuelveInfo(){
    return ("\r\nPedido " + QString::number(numero) + "\r\nCliente: " + cliente->devuelveInfo() +
            "\r\nArtículos: " +  articulos->devuelveInfo());
}

// Funciones NodoPedido
QString NodoPedido::devuelveInfo(){
    return pedido->devuelveInfo();
}

// Funciones ColaPedido
bool ColaPedido::vacia(void){
    if (frente == NULL)
        return true;
    return false;
}

void ColaPedido::encolar(Pedido * p){
    if (vacia())
        frente = new NodoPedido(p);
    else{
        NodoPedido * actual = frente;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        NodoPedido * nuevo = new NodoPedido(p);
        actual->siguiente = nuevo;
    }
}

NodoPedido * ColaPedido::desencolar(void){
    if (vacia())
        return NULL;
    else{
        NodoPedido * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = NULL;
        return borrado;
    }
}

NodoPedido * ColaPedido::verFrente(){
    return frente;
}

QString ColaPedido::devuelveInfo(void){
    QString str = "\r\nFrente";
    NodoPedido * tmp = frente;
    while (tmp != NULL){
        str += tmp->devuelveInfo();
        tmp = tmp->siguiente;
    }
    return (str + "\r\nFinal");
}

// Struct ColaPedidoPrioridad
void ColaPedidoPrioridad::encolar(Pedido * p){
    if (p->cliente->prioridad == 10)
        colaEspecial->encolar(p);
    else
        colaRegular->encolar(p);
}

NodoPedido * ColaPedidoPrioridad::desencolar(){
    if (!colaEspecial->vacia())
        return colaEspecial->desencolar();
    else
        return colaRegular->desencolar();
}

QString ColaPedidoPrioridad::devuelveInfo(){
    return ("\r\nCola prioridad: "+ colaEspecial->devuelveInfo() +
            "\r\nCola regular:" + colaRegular->devuelveInfo());
}

void ColaPedidoPrioridad::cargarEnMemoria(ListaClientes * clientes, ListaArticulos * articulos){
    QString carpeta = "ArchivosDeTexto\\Pedidos\\Entrantes\\";
    QDir directory(carpeta);
    QStringList nombresPedidos = directory.entryList(QStringList() << "*.txt" << "*.TXT", QDir::Files);
    int cant = 0;
    if (!nombresPedidos.empty()){
        for (int num = 0; num < nombresPedidos.size(); num++){
            QString nombre = nombresPedidos[num];
            QString str = retornarTextoArchivo(carpeta + nombre);
            QStringList list = separaAtributos(str);
            if (!validarFormato(list[0], reNumero)){
                str += "\r\nEl número " + list[0] + " debe ser mayor a 0.";
                crearArchivo("ArchivosDeTexto\\Pedidos\\Defectuosos\\" + nombre, str);
                QFile::remove(carpeta + nombre);
                continue;
            }
            Cliente * clienteNew = clientes->devuelveCliente(list[1]);
            if (clienteNew == NULL){
                str += "\r\nEl código " + list[1] + " no se encontró en la lista de clientes.";
                crearArchivo("ArchivosDeTexto\\Pedidos\\Defectuosos\\" + nombre, str);
                QFile::remove(carpeta + nombre);
                continue;
            }
            ListaArticulos * articulosPedidos = new ListaArticulos();
            for (int i = 2; i < list.length(); i+=2){
                Articulo * articuloNew = articulos->devuelveArticulo(list.at(i));
                if (articuloNew == NULL){
                    str += "\r\nEl código " + list.at(i) + " no se encontró en la lista de artículos.";
                    articulosPedidos->limpiarMemoria();
                    crearArchivo("ArchivosDeTexto\\Pedidos\\Defectuosos\\" + nombre, str);
                    QFile::remove(carpeta + nombre);
                    break;
                }
                articulosPedidos->insertarAlFinal(new Articulo(articuloNew->codigo, list.at(i+1).toInt(),
                                                               articuloNew->tiempoFabricacionSegundos,
                                                               articuloNew->categoria, articuloNew->ubicacionBodega));
            }
            if (articulosPedidos->largo() != 0){
                this->encolar(new Pedido(list[0].toInt(), clienteNew, articulosPedidos));
                QFile::remove(carpeta + nombre);
                cant++;
            }
        }
        qInfo() << "Largo Pedidos" << cant;
    }
    else{
        qInfo() << "Vacía";
    }
}
