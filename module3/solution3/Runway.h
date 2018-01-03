#pragma once
class Runway
{
private:
	bool status=0;							//to check the status of runway whether it is busy or not
public:
	void setStatus(bool);
	bool getStatus();
	Runway();
	~Runway();
};

