
#include "armazon.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Armazon w;
    w.show();
    return a.exec();
}
