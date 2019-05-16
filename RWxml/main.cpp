#include "tinyxml2.h"
#include "ReadFile.h"
#include "WriteConsole.h"
#include "WriteXML.h"

#define WRITE_2_CONSOLE 1
#define WRITE_2_XML 1
#define WRITE_2_XML_FILE 0

#define WRITE_PROBLEM_2_CONSOLE 1
#define WRITE_PROBLEM_2_XML 1
#define WRITE_PROBLEM_2_XML_FILE 0


int main()
{
	ReadFileClass readFile("../Satellite.pddl");
	readFile.RealAll();
	map<string, string> head = readFile.GetMostHeadPart();
	auto predicates = readFile.GetPredicates();
	auto allAction = readFile.GetAllAction();

	if (WRITE_2_CONSOLE)
	{
		WriteConsoleClass writeConsole(head, predicates, allAction);
		writeConsole.WriteHead2Console();
		writeConsole.WritePredicates2Console();
		writeConsole.WriteActions2Console();
		std::cout << std::endl << std::endl;
	}
	
	if (WRITE_2_XML)
	{
		WriteXMLClass writeFile("../Satellite.xml");
		writeFile.WriteHead(head);
		writeFile.WritePredicates(predicates);
		writeFile.WriteAllAction(allAction);
		writeFile.FinalStep(WRITE_2_XML_FILE);
	}
	
	std::cout << std::endl << std::endl << std::endl;

	ReadProblemClass readProblem("../SatelliteProblem.pddl");
	readProblem.RealAll();
	auto headProblem = readProblem.GetHeadPart();
	auto objects = readProblem.GetObjects();
	auto initProblem = readProblem.GetInit();
	auto goalProblem = readProblem.GetGoal();
	auto metricProblem = readProblem.GetMetric();

	if (WRITE_PROBLEM_2_CONSOLE)
	{
		WriteConsoleProblemClass writeProblemConsole
		(headProblem, objects, initProblem, goalProblem, metricProblem);
		writeProblemConsole.WriteHead2Console();
		writeProblemConsole.WriteObjects2Console();
		writeProblemConsole.WriteInit2Console();
		writeProblemConsole.WriteGoal2Console();
		writeProblemConsole.WriteMetric2Console();
		std::cout << std::endl << std::endl;
	}
	
	if (WRITE_PROBLEM_2_XML)
	{
		WriteProblemXMLClass writeProblemFile("../SatelliteProblem.xml");
		writeProblemFile.WriteHead(headProblem);
		writeProblemFile.WriteObjects(objects);
		writeProblemFile.WriteInitPart(initProblem);
		writeProblemFile.WriteGoalPart(goalProblem);
		writeProblemFile.WriteMetricPart(metricProblem);
		writeProblemFile.FinalStep(WRITE_PROBLEM_2_XML_FILE);
	}
	
	return 0;
	
}