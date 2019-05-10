#include "tinyxml2.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace tinyxml2;
using namespace std;

int InputXML(const char* path)
{
	XMLDocument doc; //XML开始
	doc.LoadFile(path);
	if (doc.ErrorID() != XML_SUCCESS) return doc.ErrorID(); //确保读取正确

	//仅适用于example
	auto menu = doc.FirstChildElement();
	cout << "Menu is listed as followed: " << endl << endl;
	XMLNode* node;
	int i = 0;
	for (node = menu->FirstChildElement(); node; node = node->NextSiblingElement())
	{
		cout << ++i << " is listed: " << endl;
		cout << "Name: " << node->FirstChildElement("name")->FirstChild()->Value() << endl;
		cout << "Price: " << node->FirstChildElement("price")->FirstChild()->Value() << endl;
		cout << "Description: " << node->FirstChildElement("description")->FirstChild()->Value() << endl;
		cout << "Calories: " << node->FirstChildElement("calories")->FirstChild()->Value() << endl;
		cout << endl;
	}
	return XML_SUCCESS;

}

int OutputXML(const char* path)
{
	//Articles->Article->Content,Page,count（字数）
	XMLDocument doc;
	XMLElement* root = doc.NewElement("Articles");
	doc.InsertEndChild(root);
	string s = "abcdefghijklmn";

	// 1
	auto a1 = doc.NewElement("Article");
	root->InsertEndChild(a1);
	
	auto content1 = doc.NewElement("Content");
	content1->InsertEndChild(doc.NewText(s.data()));
	content1->SetAttribute("count", (float)s.size());
	a1->InsertEndChild(content1);

	auto page1 = doc.NewElement("Page");
	auto pageNum1 = doc.NewText("10");
	page1->InsertEndChild(pageNum1);
	a1->InsertEndChild(page1);

	// 2
	auto a2 = doc.NewElement("Article");
	root->InsertEndChild(a2);

	s = "qwertyuiop{}{}";
	auto content2 = doc.NewElement("Content");
	content2->InsertEndChild(doc.NewText(s.data()));
	content2->SetAttribute("count", (float)s.size());
	a2->InsertEndChild(content2);

	auto page2 = doc.NewElement("Page");
	auto pageNum2 = doc.NewText("3");
	page2->InsertEndChild(pageNum2);
	a2->InsertEndChild(page2);

	return doc.SaveFile(path);;
}

int main()
{
	auto result = InputXML("../exampleIn.xml");
	if (result != XML_SUCCESS) return result;
	OutputXML("../exampleOut.xml");
	return 0;
	
}