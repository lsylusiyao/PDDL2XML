#include "tinyxml2.h"
#include "ReadFile.h"
#include "WriteConsole.h"
#include "WriteXML.h"

int main()
{
	ReadFileClass readFile("../Satellite.pddl");
	readFile.RealAll();
	map<string, string> head = readFile.GetMostHeadPart();
	auto predicates = readFile.GetPredicates();
	auto allAction = readFile.GetAllAction();

	/*WriteConsoleClass writeConsole(head, predicates, allAction);
	writeConsole.WriteHead2Console();
	writeConsole.WritePredicates2Console();
	writeConsole.WriteActions2Console();
	std::cout << std::endl << std::endl;*/

	/*WriteXMLClass writeFile("../Satellite.xml");
	writeFile.WriteHead(head);
	writeFile.WritePredicates(predicates);
	writeFile.WriteAllAction(allAction);
	writeFile.FinalStep(true);*/

	ReadProblemClass readProblem("../SatelliteProblem.pddl");
	readProblem.RealAll();
	auto headProblem = readProblem.GetHeadPart();
	auto objects = readProblem.GetObjects();
	auto initProblem = readProblem.GetInit();
	auto goalProblem = readProblem.GetGoal();
	auto metricProblem = readProblem.GetMetric();

	WriteConsoleProblemClass writeProblemConsole
	(headProblem, objects, initProblem, goalProblem, metricProblem);
	writeProblemConsole.WriteHead2Console();
	writeProblemConsole.WriteObjects2Console();
	writeProblemConsole.WriteInit2Console();
	writeProblemConsole.WriteGoal2Console();
	writeProblemConsole.WriteMetric2Console();
	
	return 0;
	
}