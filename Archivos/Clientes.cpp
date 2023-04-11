#include "Clientes.h"

// Funciones Cliente
void Cliente::imprimir(void){
    cout << "\nCliente " + codigo +
        "\nNombre: " + nombre +
        "\nPrioridad: " + to_string(prioridad);
}

// Funciones NodoCliente
void NodoCliente::imprimir(void){
    cliente->imprimir();
}

// Funciones ColaCliente
bool ColaCliente::vacia (void){
    if (frente == NULL)
        return true;
    else
        return false;
}

NodoCliente * ColaCliente::verFrente(){
    return frente;
}

void ColaCliente::encolarPersona (Cliente * pCliente){
    if (vacia())
        frente = new NodoCliente(pCliente);
    else{
        NodoCliente * actual = frente;
        while (actual->siguiente != NULL)
            actual = actual->siguiente;
        NodoCliente * nuevo = new NodoCliente(pCliente);
        actual->siguiente = nuevo;
    }
}

NodoCliente * ColaCliente::desencolar(void){
    if (vacia()){
        return NULL;
    }
    else{
        NodoCliente * borrado = frente;
        frente = frente->siguiente;
        borrado->siguiente = NULL;
        return borrado;
    }
}

void ColaCliente::imprimir(void){
    cout << "Frente" << endl;
    NodoCliente * tmp = frente;
    while (tmp != NULL){
        tmp->imprimir();
        tmp = tmp->siguiente;
    }
    cout << "Final" << endl;
}
