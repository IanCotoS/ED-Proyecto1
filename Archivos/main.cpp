#include <QApplication>
#include "LibreriasBasicas.h"
#include "Clientes.h"
#include "Articulos.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Archivos
    /*
    qDebug() << crearArchivoTxt("ArchivosDeTexto\\Prueba.txt", "NUEVO"); // Se agrega a la carpeta build...
                                                // Por lo tanto, se debe escribir pensando que ese el el path inicial

    qDebug() << retornarTextoArchivo("ArchivosDeTexto\\Prueba.txt");
                            // Solo así me sirvió la lectura porque la dirección no me servía, cambiarlo luego
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

    return a.exec();
}
