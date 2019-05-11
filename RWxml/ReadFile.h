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
	string eachLine; //ÿһ�е��ַ���
	std::ifstream in; //������
	string nextPath = ""; //���ܶ��һ�У���˰���������
	string* requirements;
	string* types;




	//ÿһ�ж�ȡ����ȡ֮���ɾ�����пո�ͱ�ע
	//Ȼ��ִ������ƥ�䣿ֱ�ӾͿ�ʼÿһ��ƥ��
	//һ�����������������ȡ�Ĳ���
};

