#pragma once
#include <iostream>
#include <string>
//#include "Lexer.h"
using namespace std;

enum class token_type;

class token
{
public:
	string lexeme;
	token_type type;

	token(const string& lexeme, token_type type)
	{
		this->lexeme = lexeme;
		this->type = type;
	}
};