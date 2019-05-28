#include "QtPDDL2XML.h"

QtPDDL2XML::QtPDDL2XML(QWidget *parent)
	: QMainWindow(parent),
	readDomainFile("../Satellite.pddl"),
	readProblemFile("../SatelliteProblem.pddl"),
	writeDomainFile("../Satellite.xml"),
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

void QtPDDL2XML::CreateMessage(QString title, QString message)
{
	if (title == "" || message == "")
	{
		return;
	}
	QMessageBox msg;
	msg.setWindowTitle(title);
	msg.setText(message);
	msg.show();
	msg.exec();

}

void QtPDDL2XML::CreateError(QString title, QString message)
{
	if (title == "" || message == "")
	{
		return;
	}
	QErrorMessage msg;
	msg.setWindowTitle(title);
	msg.showMessage(message);
	msg.show();
	msg.exec();

}


void QtPDDL2XML::ConnectSwitchButtons()
{
	connect(ui.switch2DomainButton, &QPushButton::clicked, [&] {ui.stackedWidget->setCurrentIndex(0); });
	connect(ui.switch2ProblemButton, &QPushButton::clicked, [&] {ui.stackedWidget->setCurrentIndex(1); });
}

void QtPDDL2XML::ConnectWriteXMLButtons()
{
	//这里判断两个is，确保读取之后再运行这个
}

void QtPDDL2XML::ConnectStartReadButtons()
{
	connect(ui.startReadDomainButton, &QPushButton::clicked, [&] {
		readDomainFile.RealAll();
		readDomainFile.ReadOthers();
		isDomainRead = true;
		CreateMessage(u8"读取文件", u8"读取Domain文件完成");
	});
	connect(ui.startReadProblemButton, &QPushButton::clicked, [&] {
		readProblemFile.RealAll();
		readProblemFile.ReadOthers();
		isProblemRead = true;
		CreateMessage(u8"读取文件", u8"读取Problem文件完成");
	});
}

void QtPDDL2XML::ConnectShowDomainDataButtons()
{
}

void QtPDDL2XML::ConnectShowProblemDataButtons()
{
}
