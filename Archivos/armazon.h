
#ifndef ARMAZON_H
#define ARMAZON_H

#include <QMainWindow>



QT_BEGIN_NAMESPACE
namespace Ui { class Armazon; }
QT_END_NAMESPACE

class Armazon : public QMainWindow

{
    Q_OBJECT

public:
    Armazon(QWidget *parent = nullptr);
    ~Armazon();

private:
    Ui::Armazon *ui;
};

#endif // ARMAZON_H
