#include "Request.h"

Request::Request()
{
}


Request::~Request()
{
}

void Request::setAeroId(string id)
{
	this->air_id = id;
}

void Request::setRequestType(string req)
{
	this->request_type = req;
}

void Request::setRequestId(string rid)
{
	this->request_id = rid;
}

string Request::getId()
{
	return this->air_id;
}

string Request::getRequestType()
{
	return this->request_type;
}

string Request::getReqId()
{
	return this->request_id;
}

void Request::setInTime(int t)
{
	this->in_time=t;
}

int Request::getInTime()
{
	return this->in_time;
}
