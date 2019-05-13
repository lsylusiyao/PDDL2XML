#include "tinyxml2.h"
#include "ReadFile.h"
#include "WriteXML.h"

int main()
{
	ReadFileClass readFile("../Satellite.pddl");
	readFile.RealAll();
	map<string, string> head = readFile.GetMostHeadPart();
	auto predicates = readFile.GetPredicates();
	auto allAction = readFile.GetAllAction();

	WriteXMLClass writeFile("../Satellite.xml");
	writeFile.WriteHead(head);
	writeFile.WritePredicates(predicates);
	writeFile.WriteAllAction(allAction);
	writeFile.FinalStep(true);
	
	return 0;
	
}