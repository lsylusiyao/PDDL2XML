#pragma once
#include "ReadFile.h"

class WriteConsoleClass
{
public:
	WriteConsoleClass(map<string, string> h,
		map<string, map<string, string>> p,
		vector<Action> va);
	void WriteHead2Console();
	void WritePredicates2Console();
	void WriteActions2Console();

private:
	map<string, string> h;
	map<string, map<string, string>> p;
	vector<Action> va;
	void WriteAction(Action a,int numMain);
	void WriteVariables(map<string, string> m, string headTab);
};


class WriteConsoleProblemClass
{
public:
	WriteConsoleProblemClass(map<string, string> h,
		map<string, string>o,
		vector<ProblemInit1> vI,
		vector<ProblemGoal1> vG,
		vector<ProblemMetric1> vM);
	void WriteHead2Console();
	void WriteObjects2Console();
	void WriteInit2Console();
	void WriteGoal2Console();
	void WriteMetric2Console();

private:
	map<string, string> head;
	map<string, string> objects;
	vector<ProblemInit1> vInit;
	vector<ProblemGoal1> vGoal;
	vector<ProblemMetric1> vMetric;
	void WriteVariables(map<string, string> m, string headTab);
};