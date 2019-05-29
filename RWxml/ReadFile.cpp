#include "ReadFile.h"
using namespace std;


ReadFileClass::ReadFileClass(const char* path)
	:in(path)
{
	fstream file;
	file.open(path);
	if (!file) throw new exception("�ļ�û���ҵ�");
}

ReadFileClass::~ReadFileClass()
{

}

void ReadFileClass::RealAll()
{
	int lineNum = 0; //�洢�е��к�
	while (getline(in,eachLine))
	{
		eachLine = regex_replace(eachLine, regex("//.*"), ""); //ɾ�����б�ע
		if (!regex_search(eachLine, regex("\\S"))) //true��ʾһ��ֻ�пո�ͻس������ɼ��ַ�������ɾ�����п���
		{
			eachLine = "";
			continue;
		}
		if (eachLine.find("domain") != -1) partNum["domain"] = lineNum;
		if (eachLine.find("requirements") != -1) partNum["requirements"] = lineNum;
		if (eachLine.find("types") != -1) partNum["types"] = lineNum;
		if (eachLine.find("predicates") != -1) partNum["predicates"] = lineNum;
		if (eachLine.find("functions") != -1) partNum["functions"] = lineNum; //�洢���п������õ��к�,function����Ϊһ����
		if (eachLine.find("action") != -1) actionNum.push_back(lineNum);

		allLine.push_back(eachLine);
		lineNum++;
		eachLine = "";
	}
}

void ReadFileClass::ReadOthers()
{
	MostHeadPart();
	Predicates();
	AllAction();
}

void ReadFileClass::MostHeadPart()
{
	smatch result;

	string tempS;
	string finalS("");

	regex_search(allLine[partNum["domain"]],result,regex("domain ([a-z]*)"));
	mostHeadPart["domain"] = result[1];

	auto result2 = RegSearch0(allLine[partNum["requirements"]], ":([a-z,-]*)");
	//regex_search(allLine[partNum["requirements"]], result, regex(":([a-z,-]*)")); //ע������ƥ��Ĳ���ȫ��
	
	for (int i = 1; i < result2.size(); i++)
	{
		tempS = result2[i];
		tempS.erase(tempS.begin());
		finalS += tempS + (i == result2.size() - 1 ? "" : ", ");
	}
	mostHeadPart["requirements"] = finalS;

	regex_search(allLine[partNum["types"]], result, regex(":types (.*)\\)"));
	mostHeadPart["types"] = regex_replace(result[1].str(), regex("\\ "), ", "); //�ո�ĳɶ��ſո�

}

void ReadFileClass::Predicates()
{
	smatch result;
	string tempS;
	string type;
	string variableType;
	string variable;
	for (int i = partNum["predicates"] + 1; i < partNum["functions"]; i++)
	{
		map<string, string> variableMap;
		tempS = allLine[i];
		regex_search(tempS, result, regex("\\(([a-z,_]+)"));
		type = result[1];
		//regex_search(tempS, result, regex("\\?([a-z,_]* - [a-z]*)"));
		auto result0 = RegSearch0(tempS, "\\?([a-z,_]* - [a-z]*)");
		for (auto r : result0) //�ҵ������еı������壬�����ұ����ͱ�������
		{
			smatch result2;
			tempS = r;
			regex_search(tempS, result2, regex("\\?([a-z,_]*) - ([a-z]*)")); //�����Ƕ���Ͳ�������������
			variable = result2[1];
			variableType = result2[2];
			variableMap[variable] = variableType;
			allType[variable] = variableType; //���Ｔʹ�Ǹ���Ҳ��Ӱ��
		}
		predicates[type] = variableMap;
		
	}

}

Action ReadFileClass::DealAction(int startLine, int endLine)
{
	Action action;
	string tempS;
	smatch result;

	tempS = allLine[startLine]; //�������ͺ�����
	if (tempS.find("(:action") != -1) // ˵����û�����͵ģ�Ҳ����˲ʱ���
	{
		action.type = "None";
	}
	else
	{
		regex_search(tempS, result, regex("\\(:([a-z]*)-action ([a-z,_]*)"));
		action.type = result[1];
		action.name = result[2];
	}
	
	//���������
	tempS = allLine[startLine + 1];
	auto result0 = RegSearch0(tempS, "\\?([a-z,_]* - [a-z]*)");
	//regex_search(tempS, result, regex("\\?([a-z,_]* - [a-z]*)"));
	for (auto r : result0)
	{
		tempS = r;
		smatch result2;
		regex_search(tempS, result2, regex("\\?([a-z,_]*) - ([a-z]*)"));
		action.param[result2[1]] = result2[2];
	}

	//����duration
	tempS = allLine[startLine + 2];
	//result0 = RegSearch0(tempS, "\\= \\?duration (.*)\\)");
	regex_search(tempS, result, regex("\\= \\?duration (.*)\\)"));
	tempS = result[1];
	if (regex_search(tempS, regex("\\d")))
	{
		action.isDurationNum = true;
		action.duration_Num = tempS;
	}
	else
	{
		action.isDurationNum = false;
		//result0 = RegSearch0(tempS, "\\(([a-z,_]*) \\?([a-z,_]*) \\?([a-z,_]*)\\)");
		regex_search(tempS, result, regex("\\(([a-z,_]*) \\?([a-z,_]*) \\?([a-z,_]*)\\)"));
		action.duration.someName = result[1];
		action.duration.param[result[2]] = action.param[result[2]];
		action.duration.param[result[3]] = action.param[result[3]];
	}
	int effectLine;
	for (int i = startLine + 3; i <= endLine; i++) //�ҵ�effect���к�
	{
		if (allLine[i].find(":effect") != -1) effectLine = i;
	}
	string mainType;
	for (int i = startLine + 3; i < effectLine; i++) //condition�����Ǵӵ����п�ʼ��ǰ���Լ��������
	{
		Composite cps;
		tempS = allLine[i];
		if (regex_search(tempS, regex(" +\\)"))) continue; //ֻ�������źͿո�û��

		if (regex_search(tempS, result, regex("(and|or)"))) mainType = result[0]; //��and or
		cps.mainType = mainType;

		regex_search(tempS, result, regex("(at start|at end|over all)")); //��at start��
		cps.keepingType = result[0];

		if (regex_search(tempS, result, regex("(not)"))) cps.itselfType = "not"; //���Ƿ���not֮���
		else cps.itselfType = "";

		regex_search(tempS, result, regex("\\(([a-z,_]*)( \\?[a-z,_]*)+"));
		cps.someName = result[1];
		tempS = result[0];
		result0 = RegSearch0(tempS, "\\?([a-z_]*)",1);
		for (int i = 0; i < result0.size(); i++)
		{
			cps.param[result0[i]] = action.param[result0[i]];
		}
		action.condition.push_back(cps);
	}

	for (int i = effectLine; i <= endLine; i++) //condition�����Ǵӵ����п�ʼ��ǰ���Լ��������
	{
		Composite cps;
		tempS = allLine[i];
		if (regex_search(tempS, regex(" +\\)"))) continue; //ֻ�������źͿո�û��

		if (regex_search(tempS, result, regex("(and|or)"))) mainType = result[0]; //��and or
		cps.mainType = mainType;

		regex_search(tempS, result, regex("(at start|at end|over all)")); //��at start��
		cps.keepingType = result[0];

		if (regex_search(tempS, result, regex("(not)"))) cps.itselfType = "not"; //���Ƿ���not֮���
		else cps.itselfType = "";

		regex_search(tempS, result, regex("\\(([a-z,_]*)( \\?[a-z,_]*)+"));
		cps.someName = result[1];
		tempS = result[0];
		result0 = RegSearch0(tempS, "\\?([a-z_]*)", 1);
		for (int i = 0; i < result0.size(); i++)
		{
			cps.param[result0[i]] = action.param[result0[i]];
		}
		action.effect.push_back(cps);

	}
	return action;
}

vector<string> ReadFileClass::RegSearch0(string s, string rs,int which)
{
	vector<string> back;
	regex patten("");
	smatch m;
	regex r(rs);
	while (regex_search(s,m,r))
	{
		back.push_back(m[which]);
		s = m.suffix().str();
	}
	return back;
}

void ReadFileClass::AllAction()
{
	for (int i = 1; i < actionNum.size() - 1; i++)
	{
		allAction.push_back(DealAction(actionNum[i], actionNum[i + 1] - 1));
	}
	allAction.push_back(DealAction(actionNum.back(), (int)allLine.size() - 2));
}



ReadProblemClass::ReadProblemClass(const char * path)
	:in(path)
{
	fstream file;
	file.open(path);
	if (!file) throw new exception("�ļ�û���ҵ�");
}

void ReadProblemClass::RealAll()
{
	int lineNum = 0; //�洢�е��к�
	while (getline(in, eachLine))
	{
		eachLine = regex_replace(eachLine, regex("//.*"), ""); //ɾ�����б�ע
		eachLine = regex_replace(eachLine, regex(";;.*"), ""); //ɾ�����б�ע
		if (!regex_search(eachLine, regex("\\S"))) //true��ʾһ��ֻ�пո�ͻس������ɼ��ַ�������ɾ�����п���
		{
			eachLine = "";
			continue;
		}
		if (eachLine.find("problem") != -1) partNum["problem"] = lineNum;
		if (eachLine.find("domain") != -1) partNum["domain"] = lineNum;
		if (eachLine.find("objects") != -1) partNum["objects"] = lineNum;
		if (eachLine.find("init") != -1) partNum["init"] = lineNum;
		if (eachLine.find("goal") != -1) partNum["goal"] = lineNum;
		if (eachLine.find("metric") != -1) partNum["metric"] = lineNum;
		lineNum++;
		allLine.push_back(eachLine);
		eachLine = "";
	}
}

void ReadProblemClass::ReadOthers()
{
	HeadPart();
	Objects();
	Init();
	Goal();
	Metric();
}

void ReadProblemClass::HeadPart()
{
	smatch result;

	string tempS;

	regex_search(allLine[partNum["problem"]], result, regex("problem ([0-9,a-z,-]*)"));
	headPart["problem"] = result[1];

	regex_search(allLine[partNum["domain"]], result, regex("domain ([a-z]*)"));
	headPart["domain"] = result[1];

}

void ReadProblemClass::Objects()
{
	string tempS;
	//smatch result;
	
	for (int i = partNum["objects"]; i < partNum["init"]; i++)
	{
		tempS = allLine[i];
		auto result = RegSearch0(tempS, "\\w+");
		//regex_search(tempS, result, regex("\\w+"));
		if(result.size() >= 2) objects[result[0]] = result[1]; //1:����2:����
	}

}

void ReadProblemClass::Init()
{
	string tempS;
	smatch result;
	for (int i = partNum["init"]; i < partNum["goal"] - 1; i++)
	{
		tempS = allLine[i];
		ProblemInit1 p;
		if (tempS.find("init") != -1) continue;
		if (regex_match(tempS, regex("\\(\\:[a-z]*\\n"))) continue;
		if (tempS.find("=") == -1) //û�ҵ�
		{
			p.isFunction = false;
			auto allFound = RegSearch0(tempS, "([a-zA-Z_\\d.]+)");
			for (auto r : allFound)
			{
				if (r == allFound[0]) { p.name = r; continue; }
				p.param[r] = objects[r];
			}
		}
		else
		{
			p.isFunction = true;
			auto allFound = RegSearch0(tempS, "([\\w\\d.]+)");
			for (auto r : allFound)
			{
				if (r == *allFound.begin()) { p.name = r; continue; }
				if (r == allFound.back()) { p.value = r; continue; }
				p.param[r] = objects[r];
			}
		}
		init.push_back(p);
	}
}

void ReadProblemClass::Goal()
{
	smatch result;
	string type;
	for (int i = partNum["goal"]; i < partNum["metric"] - 1; i++)
	{
		string tempS = allLine[i];
		ProblemGoal1 p;
		if (regex_search(tempS, regex(" +\\)"))) continue; //ֻ�������źͿո�û��
		
		if (regex_search(tempS, result, regex("and|or"))) //�ҵ�and or�ͼ�����type
			type = result[0];
		p.type = type;
		if(!regex_search(tempS, result, regex("\\((.*)\\)"))) continue; //ץ�����е�
		tempS = result[1];
		auto allFound = RegSearch0(tempS, "([\\w\\d.]+)"); //����������Ķ���ѭ��
		for (auto r : allFound)
		{
			if (r == *allFound.begin()) { p.actionName = r; continue; }
			p.param[r] = objects[r];
		}

		goal.push_back(p);
	}

}

void ReadProblemClass::Metric()
{
	string tempS = allLine[partNum["metric"]];
	auto result = RegSearch0(tempS, "([\\w\\d-.]+)");
	//regex_search(tempS, result, regex("([\\w\\d-.]+)"));
	ProblemMetric1 p;
	p.type = result[1];
	p.goal.push_back(result[2]);
	metric.push_back(p);
}

vector<string> ReadProblemClass::RegSearch0(string s, string rs, int which)
{
	vector<string> back;
	regex patten("");
	smatch m;
	regex r(rs);
	while (regex_search(s, m, r))
	{
		back.push_back(m[which]);
		s = m.suffix().str();
	}
	return back;
}