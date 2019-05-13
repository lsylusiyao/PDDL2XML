#pragma once
#include "tinyxml2.h"
#include "ReadFile.h"

class WriteXMLClass
{
public:
	WriteXMLClass(const char* p);
	void WriteHead(map<string, string> h); //���ǰ����
	void WritePredicates(map<string, map<string, string>> p); //���predicates
	void WriteAllAction(vector<Action> va); //�������action
	void FinalStep(bool write2File = true);

private:
	const char* path;
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLElement* root;

	tinyxml2::XMLElement* WriteAction(Action a); //���һ��action
	void WriteVariables(map<string, string> mapss, tinyxml2::XMLElement* toInsert);

};