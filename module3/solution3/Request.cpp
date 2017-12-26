#include "Request.h"



Request::Request()
{
}


Request::~Request()
{
}

void Request::setId(string id)
{
	this->air_id = id;
}

void Request::setReq(string req)
{
	this->request_type = req;
}

string Request::getId()
{
	return this->air_id;
}

string Request::getReq()
{
	return this->request_type;
}