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
	map<string, string>param; //使用遍历方式即可
};

struct Action
{
	string type;
	string name;
	map<string, string> param; //<变量名，变量类型>
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
	void RealAll(); //读取文件并放到allLine中
	map<string,string> GetMostHeadPart(); //把开始段的大部分处理完
	map<string, map<string, string>> GetPredicates(); //<变量名，变量类型>
	vector<Action> GetAllAction(); //处理所有action

	
private:
	Action DealAction(int startLine, int endLine);
	vector<string> RegSearch0(string s, string rs,int which = 0);

	vector<Action> allAction; //所有action
	string eachLine; //每一行的字符串
	std::ifstream in; //输入流
	vector<string> allLine; //每一行一个string
	map<string, int> partNum; //除了action之外的每一部分行号的字典
	vector<int> actionNum; //每个action的行号
	map<string, string> allType; //所有类型，字典
	

};

