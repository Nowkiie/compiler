#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Token.h"
#include "Exception.h"

using namespace std;

string key_word[] {  "н", "к", "И", "ИЛИ", "НЕ", "определить", "если", "иначе", "переход", "прервать", "выбор", "конец", "вернуть"};

enum class token_type
{
	ID, //переменная
	NUMBER, //число
	KEY_WORD, //ключевое слово
	
	DLM, // ,  ;
	ASSGN, // =
	COM, // != == > < 

	LPAR,  // ( н
	RPAR, // ) к
	PAR, // "

	MINUS, // -
	PLUS, 
	METKA, // <name>:
	OR,
	AND,
	NOT,
	STAR,
	SHIFT, // << >>
	DIV, 
};

char delimetr[] { '(', ')', ';', ' ', '-', '\n', '=', ':', '>', '<', '\t', '/', ',', '!', '+', '*'};

char invalid_del[]{'(', '=', ':', '>', '<', '!'};

string composite_del[]{ "<<", ">>", "==", "=", "!=" };

enum class States // состояния автомата
{
	S, //начальное 
	NUM, // число
	DLM, //разделитель
	WORD, //слово 
	ER, // ошибка
	FIN, //конечное

};

char hexFormat[]{ 'A', 'B', 'C', 'D', 'E', 'F' };

bool isDigit(char symbol)
{
	bool exist = find(begin(hexFormat), end(hexFormat), symbol) != end(hexFormat);
	if (symbol < '0' || symbol>'9')
	{
		if (exist) return true;
		else return false;
	}
	else return true;
}


bool isWord(char symbol)
{
	if (symbol < 'а' || symbol >'я')
	{
		if (symbol < 'А' || symbol >'Я') return false;
		else return true;
	}
	else return true;
}

bool isDelimetr(char symbol)
{
	bool exists = find(begin(delimetr), end(delimetr), symbol) != end(delimetr);
	if (exists) return true;
	else return false;
}

bool isInvalidDelimetr(char symbol)
{
	bool exists = find(begin(invalid_del), end(invalid_del), symbol) != end(invalid_del);
	if (exists) return true;
	else return false;
}

bool isCompositeDelimetr(const string& del)
{
	bool exists = find(begin(composite_del), end(composite_del), del) != end(composite_del);
	if (exists) return true;
	else return false;
}

int NumberKey(const string& temp_token)
{
	
	auto exsist = find(begin(key_word), end(key_word), temp_token);
	int res = distance( key_word, exsist);

	return res;

}

bool isKeyWord(const string& temp_token)
{
	bool exists = find(begin(key_word), end(key_word), temp_token) != end(key_word);
	if (exists) return true;
	else return false;
}

class lexer
{
private:
	string code;
	vector <token*> _tokens;
	int current_token_index = 0;
	bool flag = true;
	
public:
	int number_string = 0;

	lexer(const string& code)
	{
		this->code = code;
	}

	

	void split() //разделяем код на токены
	{
		//переменная для хранения символов, найденных до разделителя
		string temp_token; 

		States _state = States::S;//начало
		
		for (char symbol : code) //по символу строки
		{
			if (flag == true)
			{
				switch (_state)
				{
				case States::S: //+
				{
					if (isDigit(symbol))
					{
						temp_token += symbol;
						_state = States::NUM;
					}

					if (isWord(symbol) )
					{
						temp_token += symbol;
						_state = States::WORD;
					}

					// составные разделители 
					if (symbol == '=')
					{
						temp_token += symbol;
						_state = States::DLM;
					}

					if (symbol == '!')
					{
						temp_token += symbol;
						_state = States::DLM;
					}

					if (symbol == '<')
					{
						temp_token += symbol;
						_state = States::DLM;
					}

					if (symbol == '>')
					{
						temp_token += symbol;
						_state = States::DLM;
					}


					if (symbol == '-')
					{
						string symbol_token(1, symbol);

						token* new_token = new token(symbol_token, token_type::MINUS);
						_tokens.push_back(new_token);
					}

					if (symbol == '+')
					{
						string symbol_token(1, symbol);

						token* new_token = new token(symbol_token, token_type::PLUS);
						_tokens.push_back(new_token);
					}

					if (symbol == '*')
					{
						string symbol_token(1, symbol);

						token* new_token = new token(symbol_token, token_type::STAR);
						_tokens.push_back(new_token);
					}


					if (symbol == ';')
					{
						string symbol_token(1, symbol);

						token* new_token = new token(symbol_token, token_type::DLM);
						_tokens.push_back(new_token);
					}

					if (symbol == '(')
					{
						string symbol_token(1, symbol);

						token* new_token = new token(symbol_token, token_type::LPAR);
						_tokens.push_back(new_token);
					}


					if (symbol == ')')
					{
						string symbol_token(1, symbol);

						token* new_token = new token(symbol_token, token_type::RPAR);
						_tokens.push_back(new_token);
					}

					if (symbol == '\n')
					{
						number_string++;
					}

					if (!isDelimetr(symbol) && !isWord(symbol)  && !isDigit(symbol))
					{
						temp_token += symbol;
						_state = States::ER;
						break;
					}
					break;
				}
				case States::NUM: //+
				{
					if (isDigit(symbol))
					{
						temp_token += symbol;
						_state = States::NUM;
					}
					else
					{
						if (isDelimetr(symbol))
						{
							
							if (isInvalidDelimetr(symbol))
							{
								_state = States::ER;
							}
							else
							{
								token* new_token = new token(temp_token, token_type::NUMBER);
								_tokens.push_back(new_token);
								temp_token.clear();

								if (symbol == ';' || symbol == ',')
								{
									string symbol_token(1, symbol);

									token* new_token = new token(symbol_token, token_type::DLM);
									_tokens.push_back(new_token);
								}

								if (symbol == '*')
								{
									string symbol_token(1, symbol);

									token* new_token = new token(symbol_token, token_type::STAR);
									_tokens.push_back(new_token);
								}

								if (symbol == '(')
								{
									string symbol_token(1, symbol);

									token* new_token = new token(symbol_token, token_type::LPAR);
									_tokens.push_back(new_token);
								}

								if (symbol == ')')
								{
									string symbol_token(1, symbol);

									token* new_token = new token(symbol_token, token_type::RPAR);
									_tokens.push_back(new_token);
								}

								if (symbol == '\n')
								{
									number_string++;
								}

								_state = States::S;
							}
							
						}
						else
						{
							temp_token += symbol;
							_state = States::ER;
						}
					}
					break;
				}
				case States::DLM: //+
				{
					if (isDigit(symbol) || isWord(symbol) || symbol == ' ')
					{
						if (temp_token == "=")
						{
							token* new_token = new token(temp_token, token_type::ASSGN);
							_tokens.push_back(new_token);
						}
						else if (temp_token == "==" || temp_token == "!=")
						{
							token* new_token = new token(temp_token, token_type::COM);
							_tokens.push_back(new_token);
						}
						else if (temp_token == ">" || temp_token == "<")
						{
							token* new_token = new token(temp_token, token_type::COM);
							_tokens.push_back(new_token);
						}
						else if (temp_token == ">>" || temp_token == "<<")
						{
							token* new_token = new token(temp_token, token_type::SHIFT);
							_tokens.push_back(new_token);
						}
						else
						{
							_state = States::ER;
							break;
						}

						temp_token.clear();
						if (symbol != ' ')
						{
							temp_token += symbol;

						}
						if (symbol == '(' || symbol == '{')
						{
							string symbol_token(1, symbol);

							token* new_token = new token(symbol_token, token_type::LPAR);
							_tokens.push_back(new_token);
						}

						if (symbol == ')' || symbol == '}')
						{
							string symbol_token(1, symbol);

							token* new_token = new token(symbol_token, token_type::RPAR);
							_tokens.push_back(new_token);
						}

						if (symbol == '*')
						{
							string symbol_token(1, symbol);

							token* new_token = new token(symbol_token, token_type::STAR);
							_tokens.push_back(new_token);
						}


						_state = States::S;
					}
					else
					{
						temp_token += symbol;
					}

					break;
				}
				case States::WORD:
				{
					if (isDelimetr(symbol))
					{
						if (isKeyWord(temp_token))
						{
							switch (NumberKey(temp_token))
							{
							case 0:
							{
								token* new_token = new token(temp_token, token_type::LPAR);
								_tokens.push_back(new_token);
								break;
							}
							case 1:
							{
								token* new_token = new token(temp_token, token_type::RPAR);
								_tokens.push_back(new_token);
								break;
							}
							case 2:
							{
								token* new_token = new token(temp_token, token_type::AND);
								_tokens.push_back(new_token);
								break;
							}
							case 3:
							{
								token* new_token = new token(temp_token, token_type::OR);
								_tokens.push_back(new_token);
								break;
							}
							case 4:
							{
								token* new_token = new token(temp_token, token_type::NOT);
								_tokens.push_back(new_token);
								break;
							}
							default:
							{
								token* new_token = new token(temp_token, token_type::KEY_WORD);
								_tokens.push_back(new_token);
								break;
							}


							}
							_state = States::S;
						}
						else
						{
							if (symbol == ':')
							{
								token* new_token = new token(temp_token, token_type::METKA);
								_tokens.push_back(new_token);
							}
							else
							{
								token* new_token = new token(temp_token, token_type::ID);
								_tokens.push_back(new_token);
							}

							_state = States::S;

						}
						temp_token.clear();

						if (symbol == '=' || symbol == '!')
						{
							temp_token += symbol;
							_state = States::DLM;

						}
						else 
						{
							if (symbol == ';' || symbol == ',')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::DLM);
								_tokens.push_back(new_token);
							}

							if (symbol == '(')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::LPAR);
								_tokens.push_back(new_token);
							}

							if (symbol == ')')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::RPAR);
								_tokens.push_back(new_token);
							}

							if (symbol == '*')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::STAR);
								_tokens.push_back(new_token);
							}

							if (symbol == '+')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::PLUS);
								_tokens.push_back(new_token);
							}

							if (symbol == '/')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::DIV);
								_tokens.push_back(new_token);
							}

							if (symbol == '-')
							{
								string symbol_token(1, symbol);

								token* new_token = new token(symbol_token, token_type::MINUS);
								_tokens.push_back(new_token);
							}

							if (symbol == '\n')
							{
								number_string++;
							}

							
							_state = States::S;
						}
						
						
					}
					else
					{
						temp_token += symbol;
					}
					break;
				}
				case States::ER:
				{
					string message = "ошибка в строке № " + to_string(number_string) + " " + temp_token + '\n';
					throw Exception{ message };
					//cout << "ошибка в строке № " << number_string <<" "<< temp_token << '\n';
					temp_token.clear();
					_state = States::FIN;
					break;
				}
				case States::FIN:
				{
					cout << "End\n";
					flag = false;
					break;
				}
				default:
					break;
				}
			}
			
		}
	}

	void print()
	{
		for (const auto& token : _tokens)
		{
			cout << token->lexeme << " with type: ";
			switch ((int)token->type)
			{
			case 0:
			{
				cout << "ID\n";
				break;
			}
			case 1:
			{
				cout << "NUMBER\n";
				break;
			}
			case 2:
			{
				cout << "KEY_WORD\n";
				break;
			}
			case 3:
			{
				cout << "DELLIMETR\n";
				break;
			}
			case 4:
			{
				cout << "ASSIGN\n";
				break;
			}
			case 5:
			{
				cout << "COMPARE\n";
				break;
			}
			case 6:
			{
				cout << "LPAR\n";
				break;
			}
			case 7:
			{
				cout << "RPAR\n";
				break;
			}
			case 8:
			{
				cout << "PAR\n";
				break;
			}
			case 9:
			{
				cout << "MINUS\n";
				break;
			}
			case 10:
			{
				cout << "PLUS\n";
				break;
			}
			case 11:
			{
				cout << "METKA\n";
				break;
			}
			case 12:
			{
				cout << "OR\n";
				break;
			}
			case 13:
			{
				cout << "AND\n";
				break;
			}
			case 14:
			{
				cout << "NOT\n";
				break;
			}
			case 15:
			{
				cout << "STAR\n";
				break;
			}
			case 16:
			{
				cout << "SHIFT\n";
				break;
			}
			case 17:
			{
				cout << "DIV\n";
				break;
			}
			default:
				break;
			}
			
		}
	}

	void next_token()
	{
		if (current_token_index < _tokens.size() - 1)
		{
			current_token_index++;
		}

	}

	void prev_token()
	{
		if (current_token_index > 0)
		{
			current_token_index--;
		}

	}

	string current_token()
	{
		return _tokens[current_token_index]->lexeme;
	}

	token_type current_token_type()
	{
		return _tokens[current_token_index]->type;
	}

	~lexer()
	{
		_tokens.clear();
	}
};