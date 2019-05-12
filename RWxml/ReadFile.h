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
	map<string, string> param; //<变量名，变量类型>
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
	map<string, string>param; //使用遍历方式即可
};

class ReadFileClass
{
public:
	ReadFileClass(const char* path);
	~ReadFileClass();
	void RealAll();
	map<string,string> DealMostHeadPart();
	void DealPredicates(map<string, map<string, string>> &all); //<变量名，变量类型>
	void DealAction(Action &action);

private:
	string eachLine; //每一行的字符串
	std::ifstream in; //输入流
	string nextPath = ""; //可能多读一行，因此把这行留下
	vector<string> allLine;
	map<string, int> partNum;
	vector<int> actionNum;

	//每一行读取，读取之后就删除所有空格和备注
	//然后执行连续匹配？直接就开始每一层匹配
	//一个函数，获得整个读取的部分
};

