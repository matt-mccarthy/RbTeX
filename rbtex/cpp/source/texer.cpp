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
}

void Texer::cleanup(){
	std::remove(RB_FIL);
}
