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
    QWidget *widget;
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
    QWidget *layoutWidget;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QLineEdit *problemLineEdit;
    QLabel *label_8;
    QLineEdit *domainLineEdit_problem;
    QWidget *widget1;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QComboBox *problemObjectsBox;
    QPushButton *showProblemObjectsBox;
    QLabel *label_6;
    QComboBox *problemInitBox;
    QPushButton *showProblemInitBox;
    QLabel *label_7;
    QComboBox *problemGoalBox;
    QPushButton *showProblemGoalBox;
    QLabel *label_10;
    QComboBox *problemMetricBox;
    QPushButton *showProblemMetricBox;
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
        startReadDomainButton->setGeometry(QRect(20, 210, 81, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        startReadDomainButton->setFont(font1);
        domainTextBrowser = new QTextBrowser(page);
        domainTextBrowser->setObjectName(QString::fromUtf8("domainTextBrowser"));
        domainTextBrowser->setGeometry(QRect(565, 70, 411, 411));
        label_4 = new QLabel(page);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(662, 31, 72, 25));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font1);
        domainLineEdit = new QLineEdit(page);
        domainLineEdit->setObjectName(QString::fromUtf8("domainLineEdit"));
        domainLineEdit->setGeometry(QRect(750, 30, 113, 31));
        domainLineEdit->setFont(font);
        writeXMLButton = new QPushButton(page);
        writeXMLButton->setObjectName(QString::fromUtf8("writeXMLButton"));
        writeXMLButton->setGeometry(QRect(10, 40, 111, 31));
        writeXMLButton->setFont(font);
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(140, 160, 371, 131));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        domainHeadBox = new QComboBox(widget);
        domainHeadBox->setObjectName(QString::fromUtf8("domainHeadBox"));
        domainHeadBox->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(domainHeadBox, 0, 1, 1, 1);

        showDomainHeadButton = new QPushButton(widget);
        showDomainHeadButton->setObjectName(QString::fromUtf8("showDomainHeadButton"));
        showDomainHeadButton->setFont(font1);

        gridLayout->addWidget(showDomainHeadButton, 0, 2, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        domainPredicateBox = new QComboBox(widget);
        domainPredicateBox->setObjectName(QString::fromUtf8("domainPredicateBox"));
        domainPredicateBox->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(domainPredicateBox, 1, 1, 1, 1);

        showDomainPredicateButton = new QPushButton(widget);
        showDomainPredicateButton->setObjectName(QString::fromUtf8("showDomainPredicateButton"));
        showDomainPredicateButton->setFont(font1);

        gridLayout->addWidget(showDomainPredicateButton, 1, 2, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        domainActionBox = new QComboBox(widget);
        domainActionBox->setObjectName(QString::fromUtf8("domainActionBox"));
        domainActionBox->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(domainActionBox, 2, 1, 1, 1);

        showDomainActionButton = new QPushButton(widget);
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
        problemTextBrowser->setGeometry(QRect(555, 80, 411, 411));
        startReadProblemButton = new QPushButton(page_2);
        startReadProblemButton->setObjectName(QString::fromUtf8("startReadProblemButton"));
        startReadProblemButton->setGeometry(QRect(10, 220, 81, 31));
        startReadProblemButton->setFont(font1);
        writeXMLButton_Problem = new QPushButton(page_2);
        writeXMLButton_Problem->setObjectName(QString::fromUtf8("writeXMLButton_Problem"));
        writeXMLButton_Problem->setGeometry(QRect(10, 40, 111, 31));
        writeXMLButton_Problem->setFont(font);
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(630, 0, 241, 71));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        problemLineEdit = new QLineEdit(layoutWidget);
        problemLineEdit->setObjectName(QString::fromUtf8("problemLineEdit"));
        problemLineEdit->setFont(font);

        gridLayout_3->addWidget(problemLineEdit, 0, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        domainLineEdit_problem = new QLineEdit(layoutWidget);
        domainLineEdit_problem->setObjectName(QString::fromUtf8("domainLineEdit_problem"));
        domainLineEdit_problem->setFont(font);

        gridLayout_3->addWidget(domainLineEdit_problem, 1, 1, 1, 1);

        widget1 = new QWidget(page_2);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(130, 140, 341, 191));
        gridLayout_2 = new QGridLayout(widget1);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);
        label_5->setFont(font1);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        problemObjectsBox = new QComboBox(widget1);
        problemObjectsBox->setObjectName(QString::fromUtf8("problemObjectsBox"));
        problemObjectsBox->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(problemObjectsBox, 0, 1, 1, 1);

        showProblemObjectsBox = new QPushButton(widget1);
        showProblemObjectsBox->setObjectName(QString::fromUtf8("showProblemObjectsBox"));
        showProblemObjectsBox->setFont(font1);

        gridLayout_2->addWidget(showProblemObjectsBox, 0, 2, 1, 1);

        label_6 = new QLabel(widget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setFont(font1);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        problemInitBox = new QComboBox(widget1);
        problemInitBox->setObjectName(QString::fromUtf8("problemInitBox"));
        problemInitBox->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(problemInitBox, 1, 1, 1, 1);

        showProblemInitBox = new QPushButton(widget1);
        showProblemInitBox->setObjectName(QString::fromUtf8("showProblemInitBox"));
        showProblemInitBox->setFont(font1);

        gridLayout_2->addWidget(showProblemInitBox, 1, 2, 1, 1);

        label_7 = new QLabel(widget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setFont(font1);

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        problemGoalBox = new QComboBox(widget1);
        problemGoalBox->setObjectName(QString::fromUtf8("problemGoalBox"));
        problemGoalBox->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(problemGoalBox, 2, 1, 1, 1);

        showProblemGoalBox = new QPushButton(widget1);
        showProblemGoalBox->setObjectName(QString::fromUtf8("showProblemGoalBox"));
        showProblemGoalBox->setFont(font1);

        gridLayout_2->addWidget(showProblemGoalBox, 2, 2, 1, 1);

        label_10 = new QLabel(widget1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setFont(font1);

        gridLayout_2->addWidget(label_10, 3, 0, 1, 1);

        problemMetricBox = new QComboBox(widget1);
        problemMetricBox->setObjectName(QString::fromUtf8("problemMetricBox"));
        problemMetricBox->setMinimumSize(QSize(0, 25));

        gridLayout_2->addWidget(problemMetricBox, 3, 1, 1, 1);

        showProblemMetricBox = new QPushButton(widget1);
        showProblemMetricBox->setObjectName(QString::fromUtf8("showProblemMetricBox"));
        showProblemMetricBox->setFont(font1);

        gridLayout_2->addWidget(showProblemMetricBox, 3, 2, 1, 1);

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
        showProblemObjectsBox->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_6->setText(QApplication::translate("QtPDDL2XMLClass", "Init", nullptr));
        showProblemInitBox->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_7->setText(QApplication::translate("QtPDDL2XMLClass", "Goal", nullptr));
        showProblemGoalBox->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
        label_10->setText(QApplication::translate("QtPDDL2XMLClass", "Metric", nullptr));
        showProblemMetricBox->setText(QApplication::translate("QtPDDL2XMLClass", "\346\230\276\347\244\272\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtPDDL2XMLClass: public Ui_QtPDDL2XMLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPDDL2XML_H