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
	auto predicateElement = doc.NewElement("PREDICATES");
	for (auto m1 : p)
	{
		if (m1.first.size() == 0) continue;
		auto typeElement = doc.NewElement(m1.first.data()); //<on_board>
		WriteVariables(m1.second, typeElement);
		predicateElement->InsertEndChild(typeElement);
	}
	root->InsertEndChild(predicateElement);
}

void WriteXMLClass::WriteAllAction(vector<Action> va)
{
	for (auto a : va) root->InsertEndChild(WriteAction(a));
}

void WriteXMLClass::FinalStep(bool write2File)
{
	if(write2File) doc.SaveFile(path);
	else doc.Print();
}

XMLElement* WriteXMLClass::WriteAction(Action a)
{
	auto actiomElement = doc.NewElement("ACTION");

	actiomElement->SetAttribute("type", a.type.data());

	auto nameElement = doc.NewElement("NAME"); //设置name
	nameElement->InsertEndChild(doc.NewText(a.name.data()));
	actiomElement->InsertEndChild(nameElement);

	auto ParamElement = doc.NewElement("PARAM"); //设置param
	WriteVariables(a.param, ParamElement);
	actiomElement->InsertEndChild(ParamElement);

	auto durationElement = doc.NewElement("DURATION"); //设置duration
	if (a.isDurationNum) //如果只是一个数
	{
		durationElement->InsertEndChild(doc.NewText(a.duration_Num.data()));
		actiomElement->InsertEndChild(durationElement);
	}
	else //如果用函数表示
	{
		auto functionElement = doc.NewElement("function");
		functionElement->SetAttribute("name", a.duration.someName.data());
		WriteVariables(a.duration.param, functionElement);
		actiomElement->InsertEndChild(functionElement);
	}
	

	auto conditionElement = doc.NewElement("CONDITION"); //设置condition
	for (auto m1 : a.condition)
	{
		if (m1.someName.size() == 0) continue;
		auto eachElement = doc.NewElement(m1.someName.data());
		eachElement->SetAttribute("mainType", m1.mainType.data());
		eachElement->SetAttribute("keepingType", m1.keepingType.data());
		eachElement->SetAttribute("itselfType", m1.itselfType.data());
		WriteVariables(m1.param, eachElement);
		conditionElement->InsertEndChild(eachElement);
	}
	actiomElement->InsertEndChild(conditionElement);

	auto effectElement = doc.NewElement("EFFECT"); //设置condition
	for (auto m1 : a.effect)
	{
		if (m1.someName.size() == 0) continue;
		auto eachElement = doc.NewElement(m1.someName.data());
		eachElement->SetAttribute("mainType", m1.mainType.data());
		eachElement->SetAttribute("keepingType", m1.keepingType.data());
		eachElement->SetAttribute("itselfType", m1.itselfType.data());
		WriteVariables(m1.param, eachElement);
		effectElement->InsertEndChild(eachElement);
	}
	actiomElement->InsertEndChild(effectElement);

	return actiomElement;
}

void WriteXMLClass::WriteVariables(map<string, string> mapss, tinyxml2::XMLElement * toInsert)
{
	//把mpa里面的变量按照格式写入XMLElement中
	XMLElement* variable;
	for (auto m : mapss)
	{
		if (m.first.size() == 0) continue;
		variable = doc.NewElement(m.second.data()); //<instrument>
		variable->InsertEndChild(doc.NewText(m.first.data())); //i
		toInsert->InsertEndChild(variable);
	}
}




WriteProblemXMLClass::WriteProblemXMLClass(const char * p)
	:path(p)
{
	root = doc.NewElement("DOMAIN_PROBLEM");
	doc.InsertEndChild(root);
}

void WriteProblemXMLClass::WriteHead(map<string, string> h)
{
	root->SetAttribute("problem", h["problem"].data());
	root->SetAttribute("domain", h["domain"].data());
}

void WriteProblemXMLClass::WriteObjects(map<string, string> o)
{
	auto objects = doc.NewElement("OBJECTS");
	WriteVariables(o, objects);
	root->InsertEndChild(objects);
}

void WriteProblemXMLClass::WriteInitPart(vector<ProblemInit1> vI)
{
	auto init = doc.NewElement("INIT");
	for (auto i : vI)
	{
		auto eachInit = doc.NewElement(i.name.data());
		if (i.isFunction)
		{
			eachInit->SetAttribute("type", "function");
			eachInit->SetAttribute("value", i.value.data());
		}
		else
		{
			eachInit->SetAttribute("type", "action");
		}
		WriteVariables(i.param, eachInit);
		init->InsertEndChild(eachInit);
	}
	root->InsertEndChild(init);
}

void WriteProblemXMLClass::WriteGoalPart(vector<ProblemGoal1> vG)
{
	auto goal = doc.NewElement("GOAL");
	for (auto g : vG)
	{
		auto eachOne = doc.NewElement(g.actionName.data());
		eachOne->SetAttribute("mainType", g.type.data());
		WriteVariables(g.param, eachOne);
		goal->InsertEndChild(eachOne);
	}
	root->InsertEndChild(goal);
}

void WriteProblemXMLClass::WriteMetricPart(vector<ProblemMetric1> vM)
{
	auto metric = doc.NewElement("METRIC");
	for (auto m : vM)
	{
		for (auto n : m.goal)
		{
			auto eachOne = doc.NewElement(n.data());
			eachOne->SetAttribute("goal", m.type.data());
			metric->InsertEndChild(eachOne);
		}
	}
	root->InsertEndChild(metric);
}



void WriteProblemXMLClass::WriteVariables(map<string, string> mapss, tinyxml2::XMLElement * toInsert)
{
	//把mpa里面的变量按照格式写入XMLElement中
	XMLElement* variable;
	for (auto m : mapss)
	{
		if (m.first.size() == 0) continue;
		variable = doc.NewElement(m.second.data()); //<instrument>
		variable->InsertEndChild(doc.NewText(m.first.data())); //i
		toInsert->InsertEndChild(variable);
	}
}

void WriteProblemXMLClass::FinalStep(bool write2File)
{
	if (write2File) doc.SaveFile(path);
	else doc.Print();
}