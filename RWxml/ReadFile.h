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

struct Composite
{
	string type;
	string checkName;
	map<string, string>param; //ʹ�ñ�����ʽ����
};

class ReadFileClass
{
public:
	ReadFileClass(const char* path);
	~ReadFileClass();
	void RealAll();
	map<string,string> DealMostHeadPart();
	void DealPredicates(map<string, map<string, string>> &all); //<����������������>
	void DealAction(Action &action);

private:
	string eachLine; //ÿһ�е��ַ���
	std::ifstream in; //������
	string nextPath = ""; //���ܶ��һ�У���˰���������
	vector<string> allLine;
	map<string, int> partNum;
	vector<int> actionNum;

	//ÿһ�ж�ȡ����ȡ֮���ɾ�����пո�ͱ�ע
	//Ȼ��ִ������ƥ�䣿ֱ�ӾͿ�ʼÿһ��ƥ��
	//һ�����������������ȡ�Ĳ���
};

