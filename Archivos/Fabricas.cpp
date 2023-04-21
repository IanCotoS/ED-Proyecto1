#include "Fabricas.h"

// Struct ColaPedidoPrioridad
void ColaPedidoPrioridad::encolar(Pedido * p){
    for (int i = 0; i < p->articulos->largo(); i++ ){
        Articulo * p->articulos->devuelveArticulo(i);
        switch (p->articulos)
    }
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

