#include "ReadFile.h"
using namespace std;


ReadFileClass::ReadFileClass(const char* path)
	:in(path)
{
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

	regex_match(allLine[partNum["requirements"]], result, regex(":([a-z,-]*)")); //注意这里匹配的不完全对
	string tempS;
	string finalS("");
	for (int i = 1; i < result.length() - 1; i++)
	{
		tempS = result[i];
		tempS.erase(tempS.begin());
		finalS += tempS + ", ";
	}
	finalS += result[result.length() - 1];
	resultReturn["requirements"] = finalS;

	regex_match(allLine[partNum["types"]], result, regex(":types (.*)\\)"));
	tempS = result[1];
	regex_replace(tempS, regex(" "), ", "); //空格改成逗号空格
	resultReturn["types"] = tempS;

	return resultReturn;
}

map<string, map<string, string>> ReadFileClass::DealPredicates()
{
	map<string, map<string, string>> all;
	smatch result;
	string tempS;
	string type;
	string variableType;
	string variable;
	for (int i = partNum["predicates"]++; i < partNum["functions"]; i++)
	{
		map<string, string> variableMap;
		tempS = allLine[i];
		regex_match(tempS, result, regex("\\(([a-z,_]*)"));
		type = result[1];
		regex_match(tempS, result, regex("\\?([a-z,_]* - [a-z]*)"));
		for (auto r : result) //找到了所有的变量定义，下面找变量和变量类型
		{
			smatch result2;
			tempS = r;
			regex_match(tempS, result2, regex("\\?([a-z,_]*) - ([a-z]*)")); //这里是定义和参数公共的正则
			variable = result2[1];
			variableType = result2[2];
			variableMap[variable] = variableType;
			allType[variable] = variableType; //这里即使是覆盖也不影响
		}
		all[type] = variableMap;
		
	}
	return all;
}

Action ReadFileClass::DealAction(int startLine, int endLine)
{
	Action action;
	string tempS;
	smatch result;

	tempS = allLine[startLine]; //处理类型和名称
	if (tempS.find("(:action")) // 说明是没有类型的，也就是瞬时完成
	{
		action.type = "None";
	}
	else
	{
		regex_match(tempS, result, regex("\\(:([a-z]*)-action ([a-z,_]*)"));
		action.type = result[1];
		action.name = result[2];
	}
	
	//处理参数：
	tempS = allLine[startLine + 1];
	regex_match(tempS, result, regex("\\?([a-z,_]* - [a-z]*)"));
	for (auto r : result)
	{
		tempS = r;
		smatch result2;
		regex_match(tempS, result2, regex("\\?([a-z,_]*) - ([a-z]*)"));
		action.param[result2[1]] = result2[2];
	}

	//处理duration
	tempS = allLine[startLine + 2];
	regex_match(tempS, result, regex("\\= \\?duration (.*)\\)"));
	tempS = result[1];
	if (regex_match(tempS, regex("[0-9]*")))
	{
		action.isDurationNum = true;
		action.duration_Num = tempS;
	}
	else
	{
		action.isDurationNum = false;
		regex_match(tempS, result, regex("\\(([a-z,_]*) \\?([a-z,_]*) \\?([a-z,_]*)\\)"));
		action.duration.someName = result[1];
		action.duration.param[result[2]] = allType[result[2]];
		action.duration.param[result[3]] = allType[result[3]];
	}
	int effectLine;
	for (int i = startLine + 3; i <= endLine; i++) //找到effect的行号
	{
		if (allLine[i].find(":effect")) effectLine = i;
	}
	string mainType;
	for (int i = startLine + 3; i < effectLine; i++) //condition部分是从第三行开始，前面自己处理就行
	{
		tempS = allLine[i];
		if (regex_match(tempS, regex(" +\)"))) continue; //只有右括号和空格，没用

		if (regex_match(tempS, result, regex("(and|or)"))) mainType = result[0]; //找and or
		action.condition.mainType = mainType;

		regex_match(tempS, result, regex("(at start|at end|over all)")); //找at start等
		action.condition.keepingType = result[0];

		if (regex_match(tempS, result, regex("(not)"))) action.condition.itselfType = "not"; //找是否有not之类的
		else action.condition.itselfType = "";

		regex_match(tempS, result, regex("\\(([a-z,_]*)( \\?[a-z]*)+"));
		action.condition.someName = result[1];
		for (int i = 2; i < result.length(); i++)
		{
			action.condition.param[result[i]] = allType[result[i]];
		}

	}

	for (int i = effectLine; i <= endLine; i++) //condition部分是从第三行开始，前面自己处理就行
	{
		tempS = allLine[i];
		if (regex_match(tempS, regex(" +\)"))) continue; //只有右括号和空格，没用

		if (regex_match(tempS, result, regex("(and|or)"))) mainType = result[0]; //找and or
		action.effect.mainType = mainType;

		regex_match(tempS, result, regex("(at start|at end|over all)")); //找at start等
		action.effect.keepingType = result[0];

		if (regex_match(tempS, result, regex("(not)"))) action.effect.itselfType = "not"; //找是否有not之类的
		else action.effect.itselfType = "";

		regex_match(tempS, result, regex("\\(([a-z,_]*)( \\?[a-z]*)+"));
		action.effect.someName = result[1];
		for (int i = 2; i < result.length(); i++)
		{
			action.effect.param[result[i]] = allType[result[i]];
		}

	}
	return action;
}

void ReadFileClass::DealAllAction()
{
	for (int i = 0; i < actionNum.size() - 1; i++)
	{
		allAction.push_back(DealAction(actionNum[i], actionNum[i + 1] - 1));
	}
}