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
	int lineNum = 0; //存储中的行号
	while (getline(in,eachLine))
	{
		regex_replace(eachLine, noteR, ""); //删除所有备注
		if (!regex_match(eachLine, notBlankR)) //true表示一行只有空格和回车（不可见字符），即删除所有空行
		{
			eachLine = "";
			continue;
		}
		if (eachLine.find("domain")) partNum["domain"] = lineNum;
		if (eachLine.find("requirements")) partNum["requirements"] = lineNum;
		if (eachLine.find("types")) partNum["types"] = lineNum;
		if (eachLine.find("predicates")) partNum["predicates"] = lineNum;
		if (eachLine.find("functions")) partNum["functions"] = lineNum; //存储所有可能有用的行号,function就认为一个了
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

	regex_match(allLine[partNum["requirements"]], result, regex("([a-z,-]*)")); //注意这里匹配的不完全对

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
