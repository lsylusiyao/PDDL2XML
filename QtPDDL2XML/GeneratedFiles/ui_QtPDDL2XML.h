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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtPDDL2XMLClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QHBoxLayout *horizontalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *switch2ProblemButton;
    QPushButton *startReadDomainButton;
    QTextBrowser *domainTextBrowser;
    QLabel *label_4;
    QLineEdit *domainLineEdit;
    QPushButton *writeXMLButton;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *domainHeadBox;
    QPushButton *showDomainHeadButton;
    QLabel *label_2;
    QComboBox *domainPredicateBox;
    QPushButton *showDomainPredicateButton;
    QLabel *label_3;
    QComboBox *domainActionBox;
    QPushButton *showDomainActionButton;
    QWidget *page_2;
    QPushButton *switch2DomainButton;
    QTextBrowser *problemTextBrowser;
    QPushButton *startReadProblemButton;
    QPushButton *writeXMLButton_Problem;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QLineEdit *problemLineEdit;
    QLabel *label_8;
    QLineEdit *domainLineEdit_problem;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QComboBox *problemObjectsBox;
    QPushButton *showProblemObjectsButton;
    QLabel *label_6;
    QComboBox *problemInitBox;
    QPushButton *showProblemInitButton;
    QLabel *label_7;
    QComboBox *problemGoalBox;
    QPushButton *showProblemGoalButton;
    QLabel *label_10;
    QComboBox *problemMetricBox;
    QPushButton *showProblemMetricButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtPDDL2XMLClass)
    {
        if (QtPDDL2XMLClass->objectName().isEmpty())
            QtPDDL2XMLClass->setObjectName(QString::fromUtf8("QtPDDL2XMLClass"));
        QtPDDL2XMLClass->resize(1024, 600);
        centralWidget = new QWidget(QtPDDL2XMLClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1004, 526));
        horizontalLayout_2 = new QHBoxLayout(scrollAreaWidgetContents);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        stackedWidget = new QStackedWidget(scrollAreaWidgetContents);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        switch2ProblemButton = new QPushButton(page);
        switch2ProblemButton->setObjectName(QString::fromUtf8("switch2ProblemButton"));
        switch2ProblemButton->setGeometry(QRect(10, 0, 111, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        switch2ProblemButton->setFont(font);
        startReadDomainButton = new QPushButton(page);
        startReadDomainButton->setObjectName(QString::fromUtf8("startReadDomainButton"));
        startReadDomainButton->setGeometry(QRect(0, 210, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        startReadDomainButton->setFont(font1);
        domainTextBrowser = new QTextBrowser(page);
        domainTextBrowser->setObjectName(QString::fromUtf8("domainTextBrowser"));
        domainTextBrowser->setGeometry(QRect(485, 60, 491, 441));
        domainTextBrowser->setFont(font1);
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(662, 21, 72, 25));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);
        domainLineEdit = new QLineEdit(page);
        domainLineEdit->setObjectName(QString::fromUtf8("domainLineEdit"));
        domainLineEdit->setGeometry(QRect(750, 20, 113, 31));
        domainLineEdit->setFont(font);
        writeXMLButton = new QPushButton(page);
        writeXMLButton->setObjectName(QString::fromUtf8("writeXMLButton"));
        writeXMLButton->setGeometry(QRect(350, 340, 111, 31));
        writeXMLButton->setFont(font);
        layoutWidget = new QWidget(page);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 160, 371, 131));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        domainHeadBox = new QComboBox(layoutWidget);
        domainHeadBox->setObjectName(QString::fromUtf8("domainHeadBox"));
        domainHeadBox->setMinimumSize(QSize(0, 25));
        domainHeadBox->setFont(font1);

        gridLayout->addWidget(domainHeadBox, 0, 1, 1, 1);

        showDomainHeadButton = new QPushButton(layoutWidget);
        showDomainHeadButton->setObjectName(QString::fromUtf8("showDomainHeadButton"));
        showDomainHeadButton->setFont(font1);

        gridLayout->addWidget(showDomainHeadButton, 0, 2, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        domainPredicateBox = new QComboBox(layoutWidget);
        domainPredicateBox->setObjectName(QString::fromUtf8("domainPredicateBox"));
        domainPredicateBox->setMinimumSize(QSize(0, 25));
        domainPredicateBox->setFont(font1);

        gridLayout->addWidget(domainPredicateBox, 1, 1, 1, 1);

        showDomainPredicateButton = new QPushButton(layoutWidget);
        showDomainPredicateButton->setObjectName(QString::fromUtf8("showDomainPredicateButton"));
        showDomainPredicateButton->setFont(font1);

        gridLayout->addWidget(showDomainPredicateButton, 1, 2, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        domainActionBox = new QComboBox(layoutWidget);
        domainActionBox->setObjectName(QString::fromUtf8("domainActionBox"));
        domainActionBox->setMinimumSize(QSize(0, 25));
        domainActionBox->setFont(font1);

        gridLayout->addWidget(domainActionBox, 2, 1, 1, 1);

        showDomainActionButton = new QPushButton(layoutWidget);
        showDomainActionButton->setObjectName(QString::fromUtf8("showDomainActionButton"));
        showDomainActionButton->setFont(font1);

        gridLayout->addWidget(showDomainActionButton, 2, 2, 1, 1);

        gridLayout->setColumnStretch(0, 2);
        gridLayout->setColumnStretch(1, 5);
        gridLayout->setColumnStretch(2, 2);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        switch2DomainButton = new QPushButton(page_2);
        switch2DomainButton->setObjectName(QString::fromUtf8("switch2DomainButton"));
        switch2DomainButton->setGeometry(QRect(10, 0, 111, 31));
        switch2DomainButton->setFont(font);
        problemTextBrowser = new QTextBrowser(page_2);
        problemTextBrowser->setObjectName(QString::fromUtf8("problemTextBrowser"));
        problemTextBrowser->setGeometry(QRect(455, 80, 511, 421));
        problemTextBrowser->setFont(font1);
        startReadProblemButton = new QPushButton(page_2);
        startReadProblemButton->setObjectName(QString::fromUtf8("startReadProblemButton"));
        startReadProblemButton->setGeometry(QRect(10, 220, 81, 31));
        startReadProblemButton->setFont(font1);
        writeXMLButton_Problem = new QPushButton(page_2);
        writeXMLButton_Problem->setObjectName(QString::fromUtf8("writeXMLButton_Problem"));
        writeXMLButton_Problem->setGeometry(QRect(330, 360, 111, 31));
        writeXMLButton_Problem->setFont(font);
        layoutWidget1 = new QWidget(page_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(630, 0, 241, 71));
        gridLayout_3 = new QGridLayout(layoutWidget1);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        problemLineEdit = new QLineEdit(layoutWidget1);
        problemLineEdit->setObjectName(QString::fromUtf8("problemLineEdit"));
        problemLineEdit->setFont(font);

        gridLayout_3->addWidget(problemLineEdit, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        domainLineEdit_problem = new QLineEdit(layoutWidget1);
        domainLineEdit_problem->setObjectName(QString::fromUtf8("domainLineEdit_problem"));
        domainLineEdit_problem->setFont(font);

        gridLayout_3->addWidget(domainLineEdit_problem, 1, 1, 1, 1);

        layoutWidget2 = new QWidget(page_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(100, 140, 341, 191));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        problemObjectsBox = new QComboBox(layoutWidget2);
        problemObjectsBox->setObjectName(QString::fromUtf8("problemObjectsBox"));
        problemObjectsBox->setMinimumSize(QSize(0, 25));
        problemObjectsBox->setFont(font1);

        gridLayout_2->addWidget(problemObjectsBox, 0, 1, 1, 1);

        showProblemObjectsButton = new QPushButton(layoutWidget2);
        showProblemObjectsButton->setObjectName(QString::fromUtf8("showProblemObjectsButton"));
        showProblemObjectsButton->setFont(font1);

        gridLayout_2->addWidget(showProblemObjectsButton, 0, 2, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        problemInitBox = new QComboBox(layoutWidget2);
        problemInitBox->setObjectName(QString::fromUtf8("problemInitBox"));
        problemInitBox->setMinimumSize(QSize(0, 25));
        problemInitBox->setFont(font1);

        gridLayout_2->addWidget(problemInitBox, 1, 1, 1, 1);

        showProblemInitButton = new QPushButton(layoutWidget2);
        showProblemInitButton->setObjectName(QString::fromUtf8("showProblemInitButton"));
        showProblemInitButton->setFont(font1);

        gridLayout_2->addWidget(showProblemInitButton, 1, 2, 1, 1);

        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font1);

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        problemGoalBox = new QComboBox(layoutWidget2);
        problemGoalBox->setObjectName(QString::fromUtf8("problemGoalBox"));
        problemGoalBox->setMinimumSize(QSize(0, 25));
        problemGoalBox->setFont(font1);

        gridLayout_2->addWidget(problemGoalBox, 2, 1, 1, 1);

        showProblemGoalButton = new QPushButton(layoutWidget2);
        showProblemGoalButton->setObjectName(QString::fromUtf8("showProblemGoalButton"));
        showProblemGoalButton->setFont(font1);

        gridLayout_2->addWidget(showProblemGoalButton, 2, 2, 1, 1);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font1);

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        problemMetricBox = new QComboBox(layoutWidget2);
        problemMetricBox->setObjectName(QString::fromUtf8("problemMetricBox"));
        problemMetricBox->setMinimumSize(QSize(0, 25));
        problemMetricBox->setFont(font1);

        gridLayout_2->addWidget(problemMetricBox, 3, 1, 1, 1);

        showProblemMetricButton = new QPushButton(layoutWidget2);
        showProblemMetricButton->setObjectName(QString::fromUtf8("showProblemMetricButton"));
        showProblemMetricButton->setFont(font1);

        gridLayout_2->addWidget(showProblemMetricButton, 3, 2, 1, 1);

        gridLayout_2->setColumnStretch(0, 2);
        gridLayout_2->setColumnStretch(1, 5);
        gridLayout_2->setColumnStretch(2, 2);
        stackedWidget->addWidget(page_2);

        horizontalLayout_2->addWidget(stackedWidget);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        QtPDDL2XMLClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtPDDL2XMLClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 22));
        QtPDDL2XMLClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtPDDL2XMLClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtPDDL2XMLClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtPDDL2XMLClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtPDDL2XMLClass->setStatusBar(statusBar);

        retranslateUi(QtPDDL2XMLClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(QtPDDL2XMLClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtPDDL2XMLClass)
    {
        QtPDDL2XMLClass->setWindowTitle(QApplication::translate("QtPDDL2XMLClass", "QtPDDL2XML", nullptr));
        switch2ProblemButton->setText(QApplication::translate("QtPDDL2XMLClass", "\345\210\207\346\215\242\350\207\263Problem", nullptr));
        startReadDomainButton->setText(QApplication::translate("QtPDDL2XMLClass", "\345\274\200\345\247\213\350\257\273\345\217\226", nullptr));
        label_4->setText(QApplication::translate("QtPDDL2XMLClass", "Domain\357\274\232", nullptr));
        writeXMLButton->setText(QApplication::translate("QtPDDL2XMLClass", "\345\206\231\345\205\245XML\345\271\266\346\230\276\347\244\272", nullptr));
        label->setText(QApplication::translate("QtPDDL2XMLClass", "Head", nullptr));
        showDomainHeadButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_2->setText(QApplication::translate("QtPDDL2XMLClass", "Predicate", nullptr));
        showDomainPredicateButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_3->setText(QApplication::translate("QtPDDL2XMLClass", "Action", nullptr));
        showDomainActionButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        switch2DomainButton->setText(QApplication::translate("QtPDDL2XMLClass", "\345\210\207\346\215\242\350\207\263Domain", nullptr));
        startReadProblemButton->setText(QApplication::translate("QtPDDL2XMLClass", "\345\274\200\345\247\213\350\257\273\345\217\226", nullptr));
        writeXMLButton_Problem->setText(QApplication::translate("QtPDDL2XMLClass", "\345\206\231\345\205\245XML\345\271\266\346\230\276\347\244\272", nullptr));
        label_9->setText(QApplication::translate("QtPDDL2XMLClass", "Problem\357\274\232", nullptr));
        label_8->setText(QApplication::translate("QtPDDL2XMLClass", "Domain\357\274\232", nullptr));
        label_5->setText(QApplication::translate("QtPDDL2XMLClass", "Objects", nullptr));
        showProblemObjectsButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_6->setText(QApplication::translate("QtPDDL2XMLClass", "Init", nullptr));
        showProblemInitButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_7->setText(QApplication::translate("QtPDDL2XMLClass", "Goal", nullptr));
        showProblemGoalButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_10->setText(QApplication::translate("QtPDDL2XMLClass", "Metric", nullptr));
        showProblemMetricButton->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtPDDL2XMLClass: public Ui_QtPDDL2XMLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPDDL2XML_H
