#include "FileUtils.h"

#include <fstream>
#include <sstream>

std::string ReadFile(const std::string& name)
{
	std::ifstream file;
	file.open(name);
	std::stringstream fileStream;
	fileStream << file.rdbuf();
	file.close();

	return fileStream.str();
}

void WriteFile(const std::string& name, const std::string& sourse)
{
	std::ofstream file;
	file.open("out_" + name);
	file << sourse;
	file.close();
}