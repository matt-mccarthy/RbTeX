#include "../header/texer.h"
#include "../header/includes.h"
#include "../header/strutil.h"

#include <stack>

Texer::Texer(const std::string& texFile){
	file = texFile;
}

void Texer::scan(){
	std::ifstream scanner(file);
	std::ofstream writer(RB_FIL);
	std::string line;
	unsigned long long lineno = 0;
	while(std::getline(scanner,line)){
		if(sutl::contains(RUB_ENV_01,line)){
			std::stack<std::string> braces;
			size_t s = line.find("{");
			braces.push("{");
			std::string fl = line.substr(s + 1);
			while(!braces.empty() && getline(scanner,line)){
				fl += line;
				if(sutl::contains("{",line)){
					braces.push("{");
				} else if (sutl::contains("}",line)){
					braces.pop();
				}
			}
		}
	}
}
