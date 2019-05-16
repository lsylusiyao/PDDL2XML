#include "WriteConsole.h"

using namespace std;
WriteConsoleClass::WriteConsoleClass(map<string, string> h,
	map<string, map<string, string>> p,
	vector<Action> va)
	:h(h), p(p), va(va) {}

void WriteConsoleClass::WriteHead2Console()
{
	cout << "Domain" << endl;
	cout << "	Name: " << h["domain"] << endl;
	cout << "	Requirements: " << h["requirements"] << endl;
	cout << "	Types: " << h["types"] << endl;
	
}

void WriteConsoleClass::WritePredicates2Console()
{
	cout << "	Predicates: " << endl;
	for (auto m1 : p)
	{
		if (m1.first.size() == 0) continue;
		cout << "		" << m1.first << endl;
		WriteVariables(m1.second, "			");
	}
	cout << endl;
}

void WriteConsoleClass::WriteActions2Console()
{
	int numMain = 1;
	for (auto a : va)  WriteAction(a, numMain++);
}

void WriteConsoleClass::WriteAction(Action a,int numMain)
{
	cout << "Action (" << numMain << ")";
	cout <<": type is " << a.type << endl;
	cout << "	Name: " << a.name << endl;
	cout << "	Param: " << endl;
	WriteVariables(a.param, "		");
	cout << "	Duration: ";
	if (a.isDurationNum) cout << a.duration_Num << endl;
	else
	{
		cout << endl << "		function: " << a.duration.someName << endl;
		WriteVariables(a.duration.param, "			");
	}
	cout << endl;
	int num = 1;
	for (auto m1 : a.condition)
	{
		cout << "	Condition (" << num++ << ") name is : " << m1.someName << endl;
		cout << "	Type is: ";
		cout << m1.mainType << ", " << m1.keepingType;
		if (m1.itselfType != "") cout << ", " << m1.itselfType << endl;
		else cout << endl;
		WriteVariables(m1.param, "		");
		cout << endl;
	}
	num = 1;
	cout << endl;
	for (auto m1 : a.effect)
	{
		cout << "	Effect (" << num++ << ") name is : " << m1.someName << endl;
		cout << "	Type is: ";
		cout << m1.mainType << ", " << m1.keepingType;
		if (m1.itselfType != "") cout << ", " << m1.itselfType << endl;
		else cout << endl;
		WriteVariables(m1.param, "		");
		cout << endl;
	}
	

}

void WriteConsoleClass::WriteVariables(map<string, string> m, string headTab)
{
	for (auto m1 : m)
	{
		cout << headTab << m1.second << " " << m1.first << endl;
	}
}





WriteConsoleProblemClass::WriteConsoleProblemClass
(map<string, string> h, map<string, string> o, 
	vector<ProblemInit1> vI, vector<ProblemGoal1> vG, 
	vector<ProblemMetric1> vM)
	:head(h), objects(o), vInit(vI), vGoal(vG), vMetric(vM) {}

void WriteConsoleProblemClass::WriteHead2Console()
{
	cout << "Problem: " << head["problem"] << endl;
	cout << "Domain: " << head["domain"] << endl;
}

void WriteConsoleProblemClass::WriteObjects2Console()
{
	cout << "Objects: " << endl;
	WriteVariables(objects, "	");
	cout << endl;
}

void WriteConsoleProblemClass::WriteInit2Console()
{
	cout << "Init: " << endl;
	for (auto i : vInit)
	{
		if (i.isFunction)
		{
			cout << "	name: " << i.name << " (function, value = " 
				<< i.value << ")" << endl;
		}
		else
		{
			cout << "	name: " << i.name << endl;
		}
		WriteVariables(i.param, "		");

	}
	cout << endl;
}

void WriteConsoleProblemClass::WriteGoal2Console()
{
	cout << "Goal: " << endl;
	for (auto g : vGoal)
	{
		cout << "	name: " << g.actionName;
		cout << ", " << g.type << endl;
		WriteVariables(g.param, "		");
	}
	cout << endl;
}

void WriteConsoleProblemClass::WriteMetric2Console()
{
	cout << "Metric:" << endl;
	for (auto m : vMetric)
	{
		cout << "	type: " << m.type << endl;
		for (auto s : m.goal)
		{
			cout << "	goal: " << s << (s == m.goal.back() ? "" : ", ") << endl;
		}
	}
	cout << endl;
}

void WriteConsoleProblemClass::WriteVariables(map<string, string> m, string headTab)
{
	for (auto m1 : m)
	{
		cout << headTab << m1.second << " " << m1.first << endl;
	}
}