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
	Composite condition;
	Composite effect;
};



class ReadFileClass
{
public:
	ReadFileClass(const char* path);
	~ReadFileClass();
	void RealAll(); //��ȡ�ļ����ŵ�allLine��
	map<string,string> DealMostHeadPart(); //�ѿ�ʼ�εĴ󲿷ִ�����
	map<string, map<string, string>> DealPredicates(); //<����������������>
	void DealAllAction(); //��������action

	vector<Action> allAction; //����action
	map<string, string> allType; //�������ͣ��ֵ�
private:
	Action DealAction(int startLine, int endLine);

	string eachLine; //ÿһ�е��ַ���
	std::ifstream in; //������
	vector<string> allLine; //ÿһ��һ��string
	map<string, int> partNum; //����action֮���ÿһ�����кŵ��ֵ�
	vector<int> actionNum; //ÿ��action���к�
	

};

