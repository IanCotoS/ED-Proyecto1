#ifndef LIBRERIASBASICAS_H
#define LIBRERIASBASICAS_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

using namespace std;

#endif // LIBRERIASBASICAS_H

// Declaración de funciones
QString retornarTextoArchivo(QString);
QString crearArchivoTxt(QString, QString);
QStringList separaAtributos(QString);
bool validarFormato(QString, QRegularExpression);
