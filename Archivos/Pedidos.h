#ifndef PEDIDOS_H
#define PEDIDOS_H

#include "Clientes.h"
#include "Articulos.h"

#endif // PEDIDOS_H

// Declaraciones struct
struct Pedido;
struct NodoPedido;

// Structs
// Struct Pedido
struct Pedido{

    // Miembros
    int numero;
    Cliente * cliente;
    ListaArticulos * articulos;

    // Constructor
    Pedido(int pNumero, Cliente * pCliente, ListaArticulos * pArticulos){
        numero = pNumero;
        cliente = pCliente;
        articulos = pArticulos;
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct Cliente

// Struct NodoPedido
struct NodoPedido{

    // Miembros
    Pedido * pedido;
    NodoPedido * siguiente;

    // Constructores
    NodoPedido(){
        pedido = NULL;
        siguiente = NULL;
    }

    NodoPedido(Pedido * pPedido){
        pedido = pPedido;
        siguiente = NULL;
    }

    NodoPedido(int pNumeroPedido, Cliente * pCliente, ListaArticulos * pArticulos){
        pedido = new Pedido(pNumeroPedido, pCliente, pArticulos);
        siguiente = NULL;
    }

    // Encabezado de funciones
    QString devuelveInfo();
}; // Fin Struct NodoCliente

// Struct ColaPedido
struct ColaPedido{

    // Miembros
    NodoPedido * frente;

    // Constructores
    ColaPedido(){
        frente = NULL;
    }

    // Encabezados de funciones
    bool vacia(void);
    void encolar(Pedido * p);
    NodoPedido * desencolar(void);
    NodoPedido * verFrente(void);
    QString devuelveInfo(void);
}; // Fin Struct ColaPedido

// Struct ColaPedidoPrioridad
struct ColaPedidoPrioridad{

    // Miembros
    ColaPedido * colaRegular;
    ColaPedido * colaEspecial;

    // Constructores
    ColaPedidoPrioridad(){
        colaRegular = new ColaPedido();
        colaEspecial = new ColaPedido();
    }

    // Encabezados de funciones
    void encolar(Pedido * p);
    NodoPedido * desencolar();
    QString devuelveInfo();
    void cargarEnMemoria(ListaClientes * clientes, ListaArticulos * articulos);
};
