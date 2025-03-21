#pragma once

#include <iostream>

class hex_code
{
	string hc1;
	string hc2;
	string hc3;
	string hc4;

public:
	hex_code(const string& hc1, const string& hc2, const string& hc3 = "", const string& hc4 = "")
	{
		this->hc1 = hc1;
		this->hc2 = hc2;
		this->hc3 = hc3;
		this->hc4 = hc4;
	}

	string get_hc1()
	{
		return hc1;
	}

	string get_hc2()
	{
		return hc2;
	}

	string get_hc3()
	{
		return hc3;
	}

	string get_hc4()
	{
		return hc4;
	}
};
