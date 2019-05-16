#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <map>
using std::string;
using std::vector;
using std::map;

struct Composite
{	
	string mainType;
	string keepingType;
	string itselfType;
	string someName;
	map<string, string>param; //ʹ�ñ�����ʽ����
};

struct Action
{
	string type;
	string name;
	map<string, string> param; //<����������������>
	bool isDurationNum;
	string duration_Num;
	Composite duration;
	vector<Composite> condition;
	vector<Composite> effect;
};



class ReadFileClass
{
public:
	ReadFileClass(const char* path);
	~ReadFileClass();
	void RealAll(); //��ȡ�ļ����ŵ�allLine��
	map<string,string> GetMostHeadPart(); //�ѿ�ʼ�εĴ󲿷ִ�����
	map<string, map<string, string>> GetPredicates(); //<����������������>
	vector<Action> GetAllAction(); //��������action

	
private:
	Action DealAction(int startLine, int endLine);
	vector<string> RegSearch0(string s, string rs,int which = 0);

	vector<Action> allAction; //����action
	string eachLine; //ÿһ�е��ַ���
	std::ifstream in; //������
	vector<string> allLine; //ÿһ��һ��string
	map<string, int> partNum; //����action֮���ÿһ�����кŵ��ֵ�
	vector<int> actionNum; //ÿ��action���к�
	map<string, string> allType; //�������ͣ��ֵ�
	

};

struct ProblemInit1 //����һ����
{
	string name;
	bool isFunction;
	string value; // function's value
	map<string, string> param;
};

struct ProblemGoal1
{
	string type;
	string actionName;
	map<string, string> param;
};

struct ProblemMetric1
{
	string type;
	vector<string> goal;
};

class ReadProblemClass
{
public:
	ReadProblemClass(const char* path);
	void RealAll(); //��ȡ�ļ����ŵ�allLine��
	map<string, string> GetHeadPart(); //�ѿ�ʼ�εĴ󲿷ִ�����
	map<string,string> GetObjects(); //���object�ͱ���
	vector<ProblemInit1> GetInit();
	vector<ProblemGoal1> GetGoal();
	vector<ProblemMetric1> GetMetric(); //metric: <minimize>total_time</>

private:
	std::ifstream in;
	string eachLine;
	vector<string> allLine;
	vector<string> RegSearch0(string s, string rs, int which = 0);
	map<string, string> objects; //���б����ͱ������Ͷ�Ӧ
	map<string, int> partNum;
};

