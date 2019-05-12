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

