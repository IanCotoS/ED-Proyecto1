#ifndef LIBRERIASBASICAS_H
#define LIBRERIASBASICAS_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>
#include <QDir>

using namespace std;

#endif // LIBRERIASBASICAS_H

// Declaración de funciones
QString retornarTextoArchivo(QString);
QString crearArchivo(QString, QString);
QStringList separaAtributos(QString);
bool validarFormato(QString, QRegularExpression);
