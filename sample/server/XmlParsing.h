#pragma once
#include <string>
#include "rapidxml.hpp"
using namespace std;
using namespace rapidxml;
class XmlParsing
{
public:
	XmlParsing();
	~XmlParsing();
	void parse_detail(char buffer[]);

};

