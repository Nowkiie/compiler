#pragma once
#include <string>

using namespace std;



class def
{
	string name;
	int number;

public:
	def(const string& name, int number)
	{
		this->name = name;

		this->number = number;
	}

	int get_number()
	{
		return number;
	}

	string get_name()
	{
		return name;
	}
};