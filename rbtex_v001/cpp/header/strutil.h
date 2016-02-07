#ifndef STRUTIL_H
#define STRUTIL_H

#include "./includes.h"

namespace sutl{
	bool contains(const std::string &needle, const std::string& haystack){
		return haystack.find(needle) != std::string::npos;
	}
}

#endif
