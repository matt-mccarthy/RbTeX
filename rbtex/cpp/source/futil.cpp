#include "../header/futil.h"

void FileUtil::createFile(std::string& filename){
	std::ofstream strm;
	strm.open(filename);
	strm.close();
}

bool FileUtil::createFileWithContents(std::string& filename, std::string& contents){
	std::ofstream strm(filename);
	strm << contents;
	strm.close();
	return true;
}

std::string FileUtil::getFileContents(std::string& filename){
	std::ifstream strm(filename);
	if(strm.is_open()){
		std::string ret, line = "";
		while(std::getline(strm,line)){
			ret += line;
		}
		return ret;
	}
	return "";
}
