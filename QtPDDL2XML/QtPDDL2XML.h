#pragma once

#include <QtWidgets/QMainWindow>
#include <QTextBrowser>
#include <QMessageBox>
#include <QErrorMessage>
#include <QTextStream>



#include "ui_QtPDDL2XML.h"
#include "tinyxml2.h"
#include "ReadFile.h"
#include "WriteConsole.h"
#include "WriteXML.h"

class QtPDDL2XML : public QMainWindow
{
	Q_OBJECT

public:
	QtPDDL2XML(QWidget *parent = Q_NULLPTR);
	void CreateMessage(QString title, QString message);
	void CreateError(QString title, QString message);

private:
	Ui::QtPDDL2XMLClass ui;

	bool isDomainRead = false;
	bool isProblemRead = false;

	ReadFileClass readDomainFile;
	ReadProblemClass readProblemFile;
	WriteXMLClass writeDomainFile;
	WriteProblemXMLClass writeProblemFile;


	void ConnectSwitchButtons();
	void ConnectWriteXMLButtons();
	void ConnectStartReadButtons();
	void ConnectShowDomainDataButtons();
	void ConnectShowProblemDataButtons();
	void LoadDomain();
	void LoadProblem();
	void WriteAction(QTextStream &out, Action a, int numMain);
	void WriteVariables(QTextStream & out, map<string, string> m, QString headTab);
};
