#include "WriteXML.h"

using namespace tinyxml2;

WriteXMLClass::WriteXMLClass(const char * p)
	:path(p)
{
	root = doc.NewElement("DOMAIN");
	doc.InsertEndChild(root);
}

void WriteXMLClass::WriteHead(map<string, string> h)
{
	root->SetAttribute("name", h["domain"].data());

	auto requirementsElement = doc.NewElement("REQUIREMENTS");
	requirementsElement->InsertEndChild(doc.NewText(h["requirements"].data()));
	root->InsertEndChild(requirementsElement);

	auto typeElement = doc.NewElement("TYPES");
	typeElement->InsertEndChild(doc.NewText(h["types"].data()));
	root->InsertEndChild(typeElement);
}

void WriteXMLClass::WritePredicates(map<string, map<string, string>> p)
{

}

void WriteXMLClass::WriteAllAction(vector<Action> va)
{

}

void WriteXMLClass::WriteAction(Action a)
{

}
