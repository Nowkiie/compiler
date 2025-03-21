#pragma once
#include <iostream>
#include <string>

using namespace std;

class name_func
{
	string name;
public:
	name_func(const string& name)
	{
		this->name = name;
	}

	string get_name()
	{
		return name;
	}

};
