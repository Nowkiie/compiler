#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Name_func.h"


using namespace std;

class name_func_table
{
	vector <name_func*> _name_call;

public:
	name_func_table() = default;

	void push_name_table(name_func* _name)
	{
		_name_call.push_back(_name);
	}

	bool find_name(const string& name)
	{

	}

	void print_name()
	{
		for (auto& names : _name_call)
		{
			cout << names->get_name() << '\n';
		}
	}

};