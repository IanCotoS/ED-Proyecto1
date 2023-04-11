
#include "armazon.h"
#include "ui_armazon.h"


Armazon::Armazon(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Armazon)
{
    ui->setupUi(this);
}

Armazon::~Armazon()
{
    delete ui;
}


