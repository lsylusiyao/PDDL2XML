#include "QtPDDL2XML.h"

QtPDDL2XML::QtPDDL2XML(QWidget *parent)
	: QMainWindow(parent),
	readDomainFile("../Satellite.pddl"),
	readProblemFile("../SatelliteProblem.pddl"),
	writeDomainFile("../Satellite.xml"),
	writeProblemFile("../SatelliteProblem.xml") 
	//ע�⣬����������ִ򿪳������ˣ�����������û���ҵ��ļ�
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
	//�����ж�����is��ȷ����ȡ֮�����������
	connect(ui.writeXMLButton, &QPushButton::clicked, [&] {
		if (!isDomainRead)
		{
			CreateError(u8"д��XML", u8"�ļ�δ��ȡ�����ȶ�ȡ");
			return;
		}
		else
		{
			writeDomainFile.WriteHead(readDomainFile.mostHeadPart);
			writeDomainFile.WritePredicates(readDomainFile.predicates);
			writeDomainFile.WriteAllAction(readDomainFile.allAction);
			writeDomainFile.FinalStep();
			CreateMessage(u8"д��XML", u8"�ļ�д�����");
		}
	});
	connect(ui.writeXMLButton_Problem, &QPushButton::clicked, [&] {
		if (!isProblemRead)
		{
			CreateError(u8"д��XML", u8"�ļ�δ��ȡ�����ȶ�ȡ");
			return;
		}
		else
		{
			writeProblemFile.WriteHead(readProblemFile.headPart);
			writeProblemFile.WriteObjects(readProblemFile.objects);
			writeProblemFile.WriteInitPart(readProblemFile.init);
			writeProblemFile.WriteGoalPart(readProblemFile.goal);
			writeProblemFile.WriteMetricPart(readProblemFile.metric);
			writeProblemFile.FinalStep();
			CreateMessage(u8"д��XML", u8"�ļ�д�����");
		}
	});
}

void QtPDDL2XML::ConnectStartReadButtons()
{
	connect(ui.startReadDomainButton, &QPushButton::clicked, [&] {
		readDomainFile.RealAll();
		readDomainFile.ReadOthers();
		isDomainRead = true;
		LoadDomain();
		CreateMessage(u8"��ȡ�ļ�", u8"��ȡDomain�ļ����");
	});
	connect(ui.startReadProblemButton, &QPushButton::clicked, [&] {
		readProblemFile.RealAll();
		readProblemFile.ReadOthers();
		isProblemRead = true;
		LoadProblem();
		CreateMessage(u8"��ȡ�ļ�", u8"��ȡProblem�ļ����");
	});
}

void QtPDDL2XML::ConnectShowDomainDataButtons()
{

}

void QtPDDL2XML::ConnectShowProblemDataButtons()
{
}

void QtPDDL2XML::LoadDomain()
{
	ui.domainLineEdit->setText(QString::fromStdString((readDomainFile.mostHeadPart["domain"])));
	ui.domainHeadBox->addItems(QStringList::QStringList({ "ALL","domain","requirements","types" }));
	ui.domainPredicateBox->addItem("ALL");
	for (auto a : readDomainFile.predicates) //map��ȡ��һ��Ԫ�أ�Ȼ��ת����QSList
	{
		ui.domainPredicateBox->addItem(a.first.data());
	}

	ui.domainActionBox->addItem("ALL");
	for (auto a : readDomainFile.allAction) //map��ȡ��һ��Ԫ�أ�Ȼ��ת����QSList
	{
		ui.domainActionBox->addItem(a.name.data());
	}
}

void QtPDDL2XML::LoadProblem()
{
	QStringList qsl;
	bool isExist = false; //�����ظ�������ֻ��һ��
	ui.domainLineEdit_problem->setText(QString::fromStdString(readProblemFile.headPart["domain"]));
	ui.problemLineEdit->setText(QString::fromStdString(readProblemFile.headPart["problem"]));

	ui.problemObjectsBox->addItem("ALL");
	for (auto a : readProblemFile.objects) //������-����
	{
		ui.problemObjectsBox->addItem(a.first.data());
	}

	ui.problemInitBox->addItem("ALL");
	for (auto a : readProblemFile.init)
	{
		for (auto s : qsl)
		{
			if (a.name == s.toStdString()) isExist = true;
		}
		if (!isExist) qsl.push_back(QString::fromStdString(a.name));
		isExist = false;
	}
	ui.problemInitBox->addItems(qsl);
	qsl.clear();

	ui.problemGoalBox->addItem("ALL");
	for (auto a : readProblemFile.goal)
	{
		for (auto s : qsl)
		{
			if (a.actionName == s.toStdString()) isExist = true;
			
		}
		if (!isExist) qsl.push_back(QString::fromStdString(a.actionName));
		isExist = false;
	}
	ui.problemGoalBox->addItems(qsl);
	qsl.clear();

	ui.problemMetricBox->addItem("ALL");
	
}
