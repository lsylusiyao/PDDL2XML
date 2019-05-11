#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <regex>
using std::string;

class ReadFileClass
{
public:
	ReadFileClass(const char* path);
	~ReadFileClass();
	void DealWholePart();
	string DealRequirements();
	void DealTypes();
	void DealPredicates();

private:
	string eachLine; //每一行的字符串
	std::ifstream in; //输入流
	string nextPath = ""; //可能多读一行，因此把这行留下
	string* requirements;
	string* types;




	//每一行读取，读取之后就删除所有空格和备注
	//然后执行连续匹配？直接就开始每一层匹配
	//一个函数，获得整个读取的部分
};

