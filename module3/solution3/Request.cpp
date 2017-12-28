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

void Request::setInTime(time_t t)
{
	this->in_time;
}

time_t Request::getInTime()
{
	return this->in_time;
}

int Request::calculatesize()
{
	int i;
	i = request_id.size();
	return i;
}