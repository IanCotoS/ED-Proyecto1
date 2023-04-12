#include <QApplication>
#include "LibreriasBasicas.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << crearArchivoTxt("C:\\Users\\sotic\\"
                                "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt", "001\tPedro\t10\r\n002\tMaría\t5\r\n003\tJuan\t9");
    qDebug() << retornarTextoArchivo("C:\\Users\\sotic\\"
                            "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
                            // Solo así me sirvió la lectura porque la dirección no me servía, cambiarlo luego
    return a.exec();
}
