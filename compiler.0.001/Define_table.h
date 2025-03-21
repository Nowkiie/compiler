#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Define.h"

using namespace std;

class define_table
{
	vector <def*> _defs;

public:
	define_table() = default;

	void push_defs(def* _def)
	{
		_defs.push_back(_def);
	}

	int get_number_by_name(const string& name)
	{
		for (auto& def : _defs)
		{
			if (def->get_name() == name)
			{
				return def->get_number();
			}
		}

		return -1;
	}

	int size()
	{
		return _defs.size();
	}

	void print_def()
	{
		for (auto& def : _defs)
		{
			cout << def->get_name() << " n: " << def->get_number()<<'\n';
		}
	}
};