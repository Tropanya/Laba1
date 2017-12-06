#ifndef FILEUTILS_H
#define FILEUTILS_H

#include <string>

std::string ReadFile(const std::string& name);
void WriteFile(const std::string& name, const std::string& sourse);

#endif // FILEUTILS_H