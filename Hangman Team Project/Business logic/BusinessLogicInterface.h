
#pragma once
class BusinessLogicInterface
{
public:
	virtual char* display_dash()=0;
	//virtual void get_username(char*) = 0;
	virtual char* character_input(char) = 0;
	virtual int get_remaining_guess() = 0;
	virtual char* get_wrong_guess() = 0;
	virtual int get_number_of_dash() = 0;
};
