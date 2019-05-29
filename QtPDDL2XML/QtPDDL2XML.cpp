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
	connect(ui.writeXMLButton, &QPushButton::clicked, [&] {
		if (!isDomainRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		else
		{
			writeDomainFile.WriteHead(readDomainFile.mostHeadPart);
			writeDomainFile.WritePredicates(readDomainFile.predicates);
			writeDomainFile.WriteAllAction(readDomainFile.allAction);
			writeDomainFile.FinalStep();
			CreateMessage(u8"写入XML", u8"文件写入完成");
		}
	});
	connect(ui.writeXMLButton_Problem, &QPushButton::clicked, [&] {
		if (!isProblemRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
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
			CreateMessage(u8"写入XML", u8"文件写入完成");
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
		CreateMessage(u8"读取文件", u8"读取Domain文件完成");
	});
	connect(ui.startReadProblemButton, &QPushButton::clicked, [&] {
		readProblemFile.RealAll();
		readProblemFile.ReadOthers();
		isProblemRead = true;
		LoadProblem();
		CreateMessage(u8"读取文件", u8"读取Problem文件完成");
	});
}

void QtPDDL2XML::ConnectShowDomainDataButtons()
{
	connect(ui.showDomainHeadButton, &QPushButton::clicked, [&] {
		if (!isDomainRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		QString choice(ui.domainHeadBox->currentText());
		if (choice == "ALL")
		{
			out << "Requirements: " << readDomainFile.mostHeadPart["requirements"].data() << endl;
			out << "Types:" << readDomainFile.mostHeadPart["types"].data() << endl;
		}
		else if (choice == "domain")
			out << "Domain: " << readDomainFile.mostHeadPart["domain"].data() << endl;
		else if(choice == "requirements")
			out << "Requirements: " << readDomainFile.mostHeadPart["requirements"].data() << endl;
		else if(choice == "types")
			out << "Types: " << readDomainFile.mostHeadPart["types"].data() << endl;
		else return;
		ui.domainTextBrowser->setText(out.readAll());
	});

	connect(ui.showDomainPredicateButton, &QPushButton::clicked, [&] {
		if (!isDomainRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		QString choice(ui.domainPredicateBox->currentText());
		out << "Predicates: " << endl;
		if (choice == "ALL")
		{
			for (auto m1 : readDomainFile.predicates)
			{
				out << "	" << m1.first.data() << endl;
				WriteVariables(out, m1.second, "		");
			}
		}
		else
		{
			out << "	" << choice << endl;
			WriteVariables(out, readDomainFile.predicates[choice.toStdString()], "		");
		}
		out << endl;
		ui.domainTextBrowser->setText(out.readAll());
	});

	connect(ui.showDomainActionButton, &QPushButton::clicked, [&] {
		if (!isDomainRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		QString choice(ui.domainActionBox->currentText());
		if (choice == "ALL")
		{
			int actionNum = 1;
			for (auto a : readDomainFile.allAction)
				WriteAction(out, a, actionNum++);
		}
		else
		{
			/*for (auto a : readDomainFile.allAction)
			{
				if (QString::fromStdString(a.name) == choice)
					WriteAction(out, a, 0);
			}*/
			WriteAction(out, readDomainFile.allAction[ui.domainActionBox->currentIndex() - 1], 0);
		}
		ui.domainTextBrowser->setText(out.readAll());
	});
}

void QtPDDL2XML::ConnectShowProblemDataButtons()
{
	connect(ui.showProblemObjectsButton, &QPushButton::clicked, [&] {
		if (!isProblemRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		QString choice(ui.problemObjectsBox->currentText());
		out << "Object: " << endl;
		if (choice == "ALL")
		{
			WriteVariables(out, readProblemFile.objects, "	");
		}
		else
		{
			out << "	" << QString::fromStdString(readProblemFile.objects[choice.toStdString()]) << " "
				<< choice << endl;
		}
		ui.problemTextBrowser->setText(out.readAll());
	});

	connect(ui.showProblemInitButton, &QPushButton::clicked, [&] {
		if (!isProblemRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		QString choice(ui.problemInitBox->currentText());
		out << "Init: " << endl;
		bool willDisplay = false; //使用选择的选项控制willDisplay开启的时候

		for (auto i : readProblemFile.init)
		{
			if (choice == "ALL") willDisplay = true;
			else if (QString::fromStdString(i.name) == choice) willDisplay = true;

			if (willDisplay)
			{
				if (i.isFunction)
				{
					out << "	name: " << i.name.data() << " (function, value = "
						<< i.value.data() << ")" << endl;
				}
				else
				{
					out << "	name: " << i.name.data() << endl;
				}
				WriteVariables(out, i.param, "		");
				out << endl;
			}

			willDisplay = false;
		}
		ui.problemTextBrowser->setText(out.readAll());
	});

	connect(ui.showProblemGoalButton, &QPushButton::clicked, [&] {
		if (!isProblemRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		QString choice(ui.problemGoalBox->currentText());
		out << "Goal: " << endl;
		bool willDisplay = false; //使用选择的选项控制willDisplay开启的时候

		for (auto g : readProblemFile.goal)
		{
			if (choice == "ALL") willDisplay = true;
			else if (QString::fromStdString(g.actionName) == choice) willDisplay = true;
			if (willDisplay)
			{
				out << "	name: " << g.actionName.data();
				out << ", " << g.type.data() << endl;
				WriteVariables(out, g.param, "		");
			}
			willDisplay = false;
		}
		out << endl;
		ui.problemTextBrowser->setText(out.readAll());
	});

	connect(ui.showProblemMetricButton, &QPushButton::clicked, [&] {
		if (!isProblemRead)
		{
			CreateError(u8"写入XML", u8"文件未读取，请先读取");
			return;
		}
		QString data;
		QTextStream out(&data);
		out << "Metric: " << endl;
		for (auto m : readProblemFile.metric)
		{
			out << "	type: " << m.type.data() << endl;
			for (auto s : m.goal)
			{
				out << "	goal: " << s.data() << (s == m.goal.back() ? "" : ", ") << endl;
			}
		}
		out << endl;
		ui.problemTextBrowser->setText(out.readAll());
	});
}

void QtPDDL2XML::LoadDomain()
{
	ui.domainLineEdit->setText(QString::fromStdString((readDomainFile.mostHeadPart["domain"])));
	ui.domainHeadBox->addItems(QStringList::QStringList({ "ALL","domain","requirements","types" }));
	ui.domainPredicateBox->addItem("ALL");
	for (auto a : readDomainFile.predicates) //map提取第一个元素，然后转换成QSList
	{
		ui.domainPredicateBox->addItem(a.first.data());
	}

	ui.domainActionBox->addItem("ALL");
	for (auto a : readDomainFile.allAction) //map提取第一个元素，然后转换成QSList
	{
		ui.domainActionBox->addItem(a.name.data());
	}
}

void QtPDDL2XML::LoadProblem()
{
	QStringList qsl;
	bool isExist = false; //所有重复的名字只加一次
	ui.domainLineEdit_problem->setText(QString::fromStdString(readProblemFile.headPart["domain"]));
	ui.problemLineEdit->setText(QString::fromStdString(readProblemFile.headPart["problem"]));

	ui.problemObjectsBox->addItem("ALL");
	for (auto a : readProblemFile.objects) //变量名-变量
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
	for (auto m : readProblemFile.metric)
		for (auto g : m.goal) ui.problemMetricBox->addItem(QString::fromStdString(g));
	
}

void QtPDDL2XML::WriteAction(QTextStream &out, Action a, int numMain)
{
	//numMain是确定Action数目的，0就是一个，就不输出（1），如果是正整数，则是ALL模式，就依次输出
	if (numMain != 0)
		out << "Action (" << numMain << ")";
	else
		out << "Action";
	out << ": type is " << a.type.data() << endl;
	out << "	Name: " << a.name.data() << endl;
	out << "	Param: " << endl;
	WriteVariables(out, a.param, "		");
	out << "	Duration: ";
	if (a.isDurationNum) out << a.duration_Num.data() << endl;
	else
	{
		out << endl << "		function: " << a.duration.someName.data() << endl;
		WriteVariables(out, a.duration.param, "			");
	}
	out << endl;
	int num = 1;
	for (auto m1 : a.condition)
	{
		out << "	Condition (" << num++ << ") name is : " << m1.someName.data() << endl;
		out << "	Type is: ";
		out << m1.mainType.data() << ", " << m1.keepingType.data();
		if (m1.itselfType != "") out << ", " << m1.itselfType.data() << endl;
		else out << endl;
		WriteVariables(out, m1.param, "		");
		out << endl;
	}
	num = 1;
	out << endl;
	for (auto m1 : a.effect)
	{
		out << "	Effect (" << num++ << ") name is : " << m1.someName.data() << endl;
		out << "	Type is: ";
		out << m1.mainType.data() << ", " << m1.keepingType.data();
		if (m1.itselfType != "") out << ", " << m1.itselfType.data() << endl;
		else out << endl;
		WriteVariables(out, m1.param, "		");
		out << endl;
	}


}

void QtPDDL2XML::WriteVariables(QTextStream &out, map<string, string> m, QString headTab)
{
	for (auto m1 : m)
	{
		out << headTab << QString::fromStdString(m1.second) << " " << QString::fromStdString(m1.first) << endl;
	}
}