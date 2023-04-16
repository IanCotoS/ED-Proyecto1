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

QString retornarTextoArchivo(QString pNombreArchivo);
QString crearArchivoTxt(QString pNombreArchivo, QString pContenido);
