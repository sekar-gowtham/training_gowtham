#include "Runway.h"


Runway::Runway()
{

}


Runway::~Runway()
{
}

void Runway::setStatus(bool st)
{
	this->status = st;
}
bool Runway::getStatus()
{
	return this->status;
}