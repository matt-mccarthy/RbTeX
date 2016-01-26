#include "../header/texer.h"
#include "../header/includes.h"
#include "../header/strutil.h"

#include <stack>

Texer::Texer(const std::string& texFile){
	file = texFile;
}

/*
* A method that scans the TeX document for the RbTeX environments
* and copies them into rbtex_imdt.rb for later use.
*/
void Texer::scan(){
	std::ifstream scanner(file);
	std::ofstream writer(RB_FIL);
	if(writer.is_open() && scanner.is_open()){
		std::string line;
		while(std::getline(scanner,line)){
			if(sutl::contains(RUB_ENV_02_START,line)){
				while(getline(scanner,line)){
					if(sutl::contains(RUB_ENV_02_END,line))
						break;
					writer << line << std::endl;
				}
			} else if (sutl::contains(RUB_ENV_03_START,line)){
				size_t s = line.find("{");
				size_t e = line.find("}");
				std::string rbfn = line.substr(s + 1, e - s - 1);
				if(rbfn != ""){
					std::ifstream rbFile(rbfn);
					std::string rbFileContent;
					while(getline(rbFile,rbFileContent)){
						writer << rbFileContent << std::endl;
					}
				}
			}
		}
		scanner.close();
		writer.close();
	} else {
		throw std::string("Could not open files");
	}
}

void Texer::rubify(){
	std::ofstream write(RB_AUX);
	if(write.is_open()){
		write.close();
		if(system(std::string(std::string("ruby ") + std::string(RB_FIL)).c_str()) == 0){
			std::ifstream scanner(RB_AUX);
		} else {
			throw std::string("Error Compiling Ruby Code!");
		}
	} else {
		throw std::string("No Such File: ") + std::string(RB_AUX);
	}
}

void Texer::cleanup(){
	std::remove(RB_FIL);
}
