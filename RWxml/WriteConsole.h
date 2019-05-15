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