#include <QApplication>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << 2;
    return a.exec();
}
