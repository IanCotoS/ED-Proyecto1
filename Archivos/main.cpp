#include <QApplication>
#include "LibreriasBasicas.h"
#include "Clientes.h"
#include "Articulos.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /* Archivos
    qDebug() << crearArchivoTxt("C:\\Users\\sotic\\"
                                "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt", "001\tPedro\t10\r\n002\tMaría\t5\r\n003\tJuan\t9");
    qDebug() << retornarTextoArchivo("C:\\Users\\sotic\\"
                            "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
                            // Solo así me sirvió la lectura porque la dirección no me servía, cambiarlo luego
    */

    /* Pruebas Clientes
    ListaClientes * lista = new ListaClientes();
    qDebug() << lista->validarPrioridad("0");
    */

    /* Pruebas Articulos
    ListaArticulos * listaArt = new ListaArticulos();
    qDebug() << listaArt->validarCodigo("A23");
    qDebug() << listaArt->validarCantidad("2");
    qDebug() << listaArt->validarTiempo("0");
    qDebug() << listaArt->validarCategoria("B");
    qDebug() << listaArt->validarUbicacion("V43");
    qDebug() << listaArt->validarUbicacion("V00");
    qDebug() << listaArt->validarUbicacion("V10");
    qDebug() << listaArt->validarUbicacion("V11");
    */
    return a.exec();
}
