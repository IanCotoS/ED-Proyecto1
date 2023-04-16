#include <QApplication>
#include "LibreriasBasicas.h"
#include "Clientes.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << crearArchivoTxt("C:\\Users\\sotic\\"
                                "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt", "001\tPedro\t10\r\n002\tMaría\t5\r\n003\tJuan\t9");
    qDebug() << retornarTextoArchivo("C:\\Users\\sotic\\"
                            "OneDrive\\Documentos\\GitHub\\ED-Proyecto1\\Archivos\\txt\\ListaClientes.txt");
                            // Solo así me sirvió la lectura porque la dirección no me servía, cambiarlo luego
    ListaClientes * lista = new ListaClientes();
    qDebug() << lista->validarPrioridad("0");
    qDebug() << lista->validarPrioridad("11");
    qDebug() << lista->validarPrioridad("10");
    qDebug() << lista->validarCodigo("100");
    qDebug() << lista->validarCodigo("99");
    qDebug() << lista->validarCodigo("1000");
    return a.exec();
}
