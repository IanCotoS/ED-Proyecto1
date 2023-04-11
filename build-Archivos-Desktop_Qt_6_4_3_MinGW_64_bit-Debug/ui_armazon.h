/********************************************************************************
** Form generated from reading UI file 'armazon.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARMAZON_H
#define UI_ARMAZON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Armazon
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Armazon)
    {
        if (Armazon->objectName().isEmpty())
            Armazon->setObjectName("Armazon");
        Armazon->resize(800, 600);
        centralwidget = new QWidget(Armazon);
        centralwidget->setObjectName("centralwidget");
        Armazon->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Armazon);
        menubar->setObjectName("menubar");
        Armazon->setMenuBar(menubar);
        statusbar = new QStatusBar(Armazon);
        statusbar->setObjectName("statusbar");
        Armazon->setStatusBar(statusbar);

        retranslateUi(Armazon);

        QMetaObject::connectSlotsByName(Armazon);
    } // setupUi

    void retranslateUi(QMainWindow *Armazon)
    {
        Armazon->setWindowTitle(QCoreApplication::translate("Armazon", "Armazon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Armazon: public Ui_Armazon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARMAZON_H
