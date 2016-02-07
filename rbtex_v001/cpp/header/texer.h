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

#include <stdio.h>
#include <stdlib.h>

#define RB_OUTPUT "_rbtex.out.aux"
#define RB_FIL "_rbtex.rb"

#define REQUIRE_01 "require 'rbtex'"
#define RB_LINE_NUM_DELIM "#!!~~"

#define RUB_ENV_01_START "\\begin{inrbtex}"
#define RUB_ENV_01_END "\\end{inrbtex}"
#define RUB_ENV_02_START "\\begin{rbtex}"
#define RUB_ENV_02_END "\\end{rbtex}"
#define RUB_ENV_03_START "\\begin{frbtex}"
#define RUB_ENV_03_END "\\end{frbtex}"

class Texer {
public:
	Texer(const std::string& texFile);
	void scan();
	void preprocess();
	void rubify();
	void postprocess();
	void cleanup();
private:
	std::string file;
	std::string auxFile;
	std::string rubyFile;
};

#endif
