#include "Runway.h"


Runway::Runway()
{
}


Runway::~Runway()
{
}

void Runway::setStatus(bool status)
{
	this->status = status;
}
bool Runway::getStatus()
{
	return this->status;
}