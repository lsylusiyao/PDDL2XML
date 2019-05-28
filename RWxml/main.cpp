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
	readFile.ReadOthers();

	if (WRITE_2_CONSOLE)
	{
		WriteConsoleClass writeConsole(readFile.mostHeadPart, readFile.predicates, readFile.allAction);
		writeConsole.WriteHead2Console();
		writeConsole.WritePredicates2Console();
		writeConsole.WriteActions2Console();
		std::cout << std::endl << std::endl;
	}
	
	if (WRITE_2_XML)
	{
		WriteXMLClass writeFile("../Satellite.xml");
		writeFile.WriteHead(readFile.mostHeadPart);
		writeFile.WritePredicates(readFile.predicates);
		writeFile.WriteAllAction(readFile.allAction);
		writeFile.FinalStep(WRITE_2_XML_FILE);
	}
	
	std::cout << std::endl << std::endl << std::endl;

	ReadProblemClass readProblem("../SatelliteProblem.pddl");
	readProblem.RealAll();
	readProblem.ReadOthers();

	if (WRITE_PROBLEM_2_CONSOLE)
	{
		WriteConsoleProblemClass writeProblemConsole
		(readProblem.headPart, readProblem.objects, 
			readProblem.init, readProblem.goal, readProblem.metric);
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
		writeProblemFile.WriteHead(readProblem.headPart);
		writeProblemFile.WriteObjects(readProblem.objects);
		writeProblemFile.WriteInitPart(readProblem.init);
		writeProblemFile.WriteGoalPart(readProblem.goal);
		writeProblemFile.WriteMetricPart(readProblem.metric);
		writeProblemFile.FinalStep(WRITE_PROBLEM_2_XML_FILE);
	}
	
	return 0;
	
}