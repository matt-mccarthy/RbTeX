#ifndef RBTEX_H
#define RBTEX_H

#include "./futil.h"
#include <map>
#include <vector>

class Texer {
public:
	Texer(std::string& texFile);
	void scan();
private:
	std::string file;
	std::map<int,std::string> refs;
};

#endif
