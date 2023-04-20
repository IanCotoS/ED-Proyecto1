#include <LibreriasBasicas.h>

QString retornarTextoArchivo(QString pNombreArchivo){
    QFile file(pNombreArchivo);
    QString texto;
    if (!file.exists()){
        texto += "El archivo " + pNombreArchivo + " no existe.";
    }
    else if (!file.open(QIODevice::ReadOnly)){
        texto += file.errorString();
    }
    else{
        QTextStream stream(&file);
        texto = stream.readAll();
        //while (!stream.atEnd()){ Línea por línea
        //    texto.append(stream.readLine() + "\n");
        //}
    }
    file.close();
    return texto;
}

QString crearArchivo(QString pNombreArchivo, QString pContenido){
    QFile file(pNombreArchivo);
    QString texto;
    if (!file.open(QIODevice::WriteOnly)){
        texto += file.errorString();
    }
    else{
        QTextStream stream(&file);
        stream << pContenido;
        texto += "Se creó el archivo " + pNombreArchivo + ".";
    }
    file.close();
    return texto;
}

QStringList separaAtributos(QString str){
    // Separa los datos en una lista temporal por \t y \r\n
    static QRegularExpression re("\\t");
    return str.replace("\r\n", "\t").split(re); // Cambia el salto de línea por tab, y lo separa todo en una lista
}

bool validarFormato(QString pString, QRegularExpression pExpresionRegular){
    // Valida el formato de la expresión regular contra el string
    QRegularExpressionMatch match = pExpresionRegular.match(pString);
    return match.hasMatch();
}
