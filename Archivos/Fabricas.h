#ifndef FABRICAS_H
#define FABRICAS_H

#import "LibreriasBasicas.h"
#import "Pedidos.h"

#endif // FABRICAS_H


// Declaración de structs
struct Fabricas;
struct ColaFabricas;

// Structs
// Struct Fabricas

struct Fabricas{

    // Miembros


    // Constructores


    // Declaraciones de funciones

};

struct ColaFabricas{

    // Miembros
    ColaPedido * colaFabricaA;
    ColaPedido * colaFabricaB;
    ColaPedido * colaFabricaC;
    ColaPedido * colaFabricaComodin;

    // Constructores
    ColaFabricas(){
        colaFabricaA = new ColaPedido();
        colaFabricaB = new ColaPedido();
        colaFabricaC = new ColaPedido();
        colaFabricaComodin = new ColaPedido();
    }

    // Encabezados de funciones
    void encolar(Pedido * p);
    NodoPedido * desencolar();
    QString devuelveInfo();
    void cargarEnMemoria(ListaClientes * clientes, ListaArticulos * articulos);

};

