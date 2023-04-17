#include <QApplication>
#include "LibreriasBasicas.h"
#include "Clientes.h"
#include "Articulos.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /*Archivos
    qDebug() << crearArchivoTxt("C:\\Users\\sotic\\"
                                "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt", "001\tPedro\t10\r\n002\tMaría\t5\r\n003\tJuan\t9");
    qDebug() << retornarTextoArchivo("C:\\Users\\sotic\\"
                            "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
                            // Solo así me sirvió la lectura porque la dirección no me servía, cambiarlo luego
    */

    // Pruebas Clientes
    ListaClientes * listaClientes = new ListaClientes();
    if(listaClientes->cargarEnMemoria())
        qInfo() << listaClientes->devuelveInfo();
    else{
        qInfo() << "Falló";
    }

    // Pruebas Articulos
    ListaArticulos * listaArticulos = new ListaArticulos();
    if(listaArticulos->cargarEnMemoria())
        qInfo() << listaArticulos->devuelveInfo();
    else{
        qInfo() << "Falló";
    }

    return a.exec();
}
