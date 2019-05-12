#pragma once
#include "tinyxml2.h"
#include "ReadFile.h"

class WriteXMLClass
{
public:
	WriteXMLClass(const char* p);
	void WriteHead(map<string, string> h);
	void WritePredicates(map<string, map<string, string>> p);
	void WriteAllAction(vector<Action> va);

private:
	const char* path;
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root;

	void WriteAction(Action a);

};