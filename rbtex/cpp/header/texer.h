/*
* texer.h
*
* The header file describing the core tex interface for the package.
*
* @author Steven Rosendahl
* @version 1.0.0
*
*/

#ifndef RBTEX_H
#define RBTEX_H

#include "./futil.h"
#include "../header/includes.h"

#define RB_AUX ".rtx.aux"
#define RB_FIL "rbtex_imdt.rb"

#define RUB_ENV_01 "inrbtex"
#define RUB_ENV_02 "rbtex"
#define RUB_ENV_03 "frbtex"

class Texer {
public:
	Texer(std::string& texFile);
	void scan();
	void preprocess();
	void rubify();
	void postprocess();
private:
	std::string file;
	std::map<unsigned long long,std::string> refs;
};

#endif
