#pragma once
#include <iostream>
#include <string>

using namespace std;

class triad
{
	string operation;
	int number_reg;
	int number_or_reg;

public:
	triad(const string& operation, int numb_reg, int number_or_reg)
	{
		this->operation = operation;
		this->number_reg = numb_reg;
		this->number_or_reg = number_or_reg;
	}

	string get_operation()
	{
		return operation;
	}

	int get_num_reg()
	{
		return number_reg;
	}

	int get_num_or_reg()
	{
		return number_or_reg;
	}
};
