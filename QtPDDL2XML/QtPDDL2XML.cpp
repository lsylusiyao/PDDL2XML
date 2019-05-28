#include "QtPDDL2XML.h"

QtPDDL2XML::QtPDDL2XML(QWidget *parent)
	: QMainWindow(parent),
	readFile("../Satellite.pddl"),
	readProblem("../SatelliteProblem.pddl"),
	writeFile("../Satellite.xml"),
	writeProblemFile("../SatelliteProblem.xml") 
	//注意，这里如果出现打开程序闪退，可能是这里没有找到文件
{
	ui.setupUi(this);
	ConnectSwitchButtons();
	ConnectStartReadButtons();
	ConnectWriteXMLButtons();
	ConnectShowDomainDataButtons();
	ConnectShowProblemDataButtons();
}

void QtPDDL2XML::ConnectSwitchButtons()
{
	
}

void QtPDDL2XML::ConnectWriteXMLButtons()
{
}

void QtPDDL2XML::ConnectStartReadButtons()
{
}

void QtPDDL2XML::ConnectShowDomainDataButtons()
{
}

void QtPDDL2XML::ConnectShowProblemDataButtons()
{
}
