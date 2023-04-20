#include <QApplication>
#include "LibreriasBasicas.h"
#include "Pedidos.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Archivos
    /*
    qDebug() << crearArchivo("ArchivosDeTexto\\Prueba.txt", "NUEVO\t"); // Se agrega a la carpeta build...
                                                // Por lo tanto, se debe escribir pensando que ese el el path inicial
    qDebug() << retornarTextoArchivo("ArchivosDeTexto\\Prueba.txt");
    QString str = retornarTextoArchivo("C:\\Users\\sotic\\"
                         "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
    qDebug() << separaAtributos(str);
    */


    // Pruebas Clientes
    ListaClientes * listaClientes = new ListaClientes();
    if(listaClientes->cargarEnMemoria())
        qInfo() << "\r\nLista de Clientes:\r\n" << listaClientes->devuelveInfo();


    // Pruebas Articulos
    ListaArticulos * listaArticulos = new ListaArticulos();
    if(listaArticulos->cargarEnMemoria())
        qInfo() << "\r\nLista de Articulos:\r\n" << listaArticulos->devuelveInfo();

    ColaPedidoPrioridad * colaPedido = new ColaPedidoPrioridad();
    colaPedido->cargarEnMemoria(listaClientes, listaArticulos);
    qInfo() << "\r\nCola de prioridad:\r\n"; //<< colaPedido->devuelveInfo();
    qInfo() << colaPedido->desencolar()->devuelveInfo();
    qInfo() << colaPedido->desencolar()->devuelveInfo();
    qInfo() << colaPedido->desencolar()->devuelveInfo();
    return a.exec();
}
