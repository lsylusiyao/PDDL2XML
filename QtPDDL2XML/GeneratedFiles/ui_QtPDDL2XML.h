/********************************************************************************
** Form generated from reading UI file 'QtPDDL2XML.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPDDL2XML_H
#define UI_QTPDDL2XML_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPDDL2XMLClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtPDDL2XMLClass)
    {
        if (QtPDDL2XMLClass->objectName().isEmpty())
            QtPDDL2XMLClass->setObjectName(QString::fromUtf8("QtPDDL2XMLClass"));
        QtPDDL2XMLClass->resize(600, 400);
        menuBar = new QMenuBar(QtPDDL2XMLClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtPDDL2XMLClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtPDDL2XMLClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtPDDL2XMLClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtPDDL2XMLClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtPDDL2XMLClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtPDDL2XMLClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtPDDL2XMLClass->setStatusBar(statusBar);

        retranslateUi(QtPDDL2XMLClass);

        QMetaObject::connectSlotsByName(QtPDDL2XMLClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtPDDL2XMLClass)
    {
        QtPDDL2XMLClass->setWindowTitle(QApplication::translate("QtPDDL2XMLClass", "QtPDDL2XML", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtPDDL2XMLClass: public Ui_QtPDDL2XMLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPDDL2XML_H
