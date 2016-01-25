/**
* futil.h
*
* A header file defining useful file I/O operations
*/

#ifndef FUTIL_H
#define FUTIL_H

#include <iostream>
#include <fstream>
#include <string>

class FileUtil {
public:
	static void createFile(std::string& filename);
	static bool createFileWithContents(std::string& filename, std::string& contents);
	static std::string getFileContents(std::string& filename);
};

#endif
