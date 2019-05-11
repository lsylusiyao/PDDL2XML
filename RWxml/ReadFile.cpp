#include "ReadFile.h"

ReadFileClass::ReadFileClass(const char* path)
{
	std::ifstream in(path);
}

ReadFileClass::~ReadFileClass()
{
}