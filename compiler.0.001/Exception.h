#pragma once
#include <iostream>

using namespace std;

class Exception
{
public:
	Exception(const string& message)
	{
		this->message = message;
	}

	string getMessage()
	{
		return message;
	}

private:
	string message;
};