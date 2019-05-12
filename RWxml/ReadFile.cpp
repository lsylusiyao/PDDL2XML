#include "ReadFile.h"
using namespace std;


ReadFileClass::ReadFileClass(const char* path)
{
	ifstream in(path);
}

ReadFileClass::~ReadFileClass()
{

}

void ReadFileClass::RealAll()
{
	regex notBlankR("\\S");
	regex noteR("//.*");
	int lineNum = 0; //�洢�е��к�
	while (getline(in,eachLine))
	{
		regex_replace(eachLine, noteR, ""); //ɾ�����б�ע
		if (!regex_match(eachLine, notBlankR)) //true��ʾһ��ֻ�пո�ͻس������ɼ��ַ�������ɾ�����п���
		{
			eachLine = "";
			continue;
		}
		if (eachLine.find("domain")) partNum["domain"] = lineNum;
		if (eachLine.find("requirements")) partNum["requirements"] = lineNum;
		if (eachLine.find("types")) partNum["types"] = lineNum;
		if (eachLine.find("predicates")) partNum["predicates"] = lineNum;
		if (eachLine.find("functions")) partNum["functions"] = lineNum; //�洢���п������õ��к�,function����Ϊһ����
		if (eachLine.find("action")) actionNum.push_back(lineNum);

		allLine.push_back(eachLine);
		lineNum++;
		eachLine = "";
	}
}

map<string, string> ReadFileClass::DealMostHeadPart()
{
	map<string, string>resultReturn;
	smatch result;

	regex_match(allLine[partNum["domain"]],result,regex("domain ([a-z]*)"));
	resultReturn["domain"] = result[1];

	regex_match(allLine[partNum["requirements"]], result, regex("([a-z,-]*)")); //ע������ƥ��Ĳ���ȫ��

	resultReturn["domain"] = result[1];

	regex_match(allLine[partNum["domain"]], result, regex("domain ([a-z]*)"));
	resultReturn["domain"] = result[1];

	regex_match(allLine[partNum["domain"]], result, regex("domain ([a-z]*)"));
	resultReturn["domain"] = result[1];
	return resultReturn;
}

void ReadFileClass::DealPredicates(map<string, map<string, string>> &all)
{

}

void ReadFileClass::DealAction(Action & action)
{

}
