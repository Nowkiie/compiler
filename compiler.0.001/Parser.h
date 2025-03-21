#pragma once
#include <iostream>
#include <string>
#include "Lexer.h"
#include "AST.h"
#include "Exception.h"
#include "TriadList.h"

using namespace std;

class parser
{
private:
	lexer* _lex;
	ast* _ast;
	triadList* _all_triads;

	int count_lpar = 0; //кол-во открывающихся скобок
	int count_condition = 0; //кол-во операторов if
	
	string message = "Ошибка в строке № ";

public:

	parser(const string& code)
	{
		_lex = new lexer(code);
		_ast = new ast();
		_all_triads = new triadList();
	}
private:

	node* code()
	{
		
		//директива
		if (_lex->current_token() == "определить")
		{
			_lex->next_token();
			node* define_node = define();

			_lex->next_token();
			if (_lex->current_token() != "к")
			{
				node* temp_code_node = code();
				node* new_node = new node(node_type::CODE, "", define_node, temp_code_node);
				return new_node;
			}

			node* new_node = new node(node_type::CODE, "", define_node);
			return new_node;
		}

		//процедура
		if (_lex->current_token_type() == token_type::ID)
		{
			node* proc_node = procedure();

			_lex->next_token();
			if (_lex->current_token() != "к")
			{
				node* temp_code_node = code();
				node* new_node = new node(node_type::CODE, "", proc_node, temp_code_node);
				return new_node;
			}

			node* new_node = new node(node_type::CODE, "", proc_node);
			return new_node;


			return new_node;
		}

	}


	node* procedure()
	{
		string name_proc = _lex->current_token();
		if (_lex->current_token_type() != token_type::ID)
		{
			message = message + to_string(_lex->number_string)+": "+ "ожидалось имя процедуры";
			throw Exception{ message};
		}

		//параметры
		_lex->next_token();
		if (_lex->current_token() == "(")
		{
			_lex->next_token();
			node* parametr_node = parametr();

			_lex->next_token();
			if (_lex->current_token() != "н")
			{
				message = message + to_string(_lex->number_string) + ": " + "ожидалось 'н'";
				throw Exception{ message };
				//error("'н' exepted");
			}

			
			_lex->next_token();
			if (_lex->current_token() == "к")
			{
				message = message + to_string(_lex->number_string) + ": " + "ожидалось описание функции";
				throw Exception{ message };
			}
			node* proc_node = proc_code();

			node* new_node = new node(node_type::PROC, name_proc, parametr_node, proc_node);
			return new_node;
		}

		//нет параметров
		if (_lex->current_token() != "н")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось 'н'";
			throw Exception{ message };
			//error("'н' exepted");
		}

		
		_lex->next_token();
		if (_lex->current_token() == "к")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось описание функции";
			throw Exception{ message };
		}
		node* proc_node = proc_code();

		node* new_node = new node(node_type::PROC, name_proc, proc_node);
		return new_node;
	}

	node* proc_code()
	{
		node* operation_node = operation();

		_lex->next_token();
		if (_lex->current_token() != "к")
		{
			node* temp_operation_node = proc_code();

			node* new_node = new node(node_type::PROC_CODE, "", operation_node, temp_operation_node);
			return new_node;
		}

		node* new_node = new node(node_type::PROC_CODE, "", operation_node);
		return new_node;
	}

	node* operation()
	{
		if (_lex->current_token_type() == token_type::ID)
		{
			node* action_node = action();
			return action_node;
		}

		if (_lex->current_token_type() == token_type::METKA)
		{
			string metka_name = _lex->current_token();

			node* new_node = new node(node_type::METKA, metka_name);
			return new_node;
		}

		if (_lex->current_token() == "вернуть")
		{
			_lex->next_token();
			node* value1 = value();

			_lex->next_token();
			if (_lex->current_token() != ";")
			{
				message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
				throw Exception{ message };
			}

			node* new_node = new node(node_type::RETURN, "", value1);
			return new_node;
		}

		if (_lex->current_token() == "переход")
		{
			//имя перехода
			_lex->next_token();
			string name_goto = _lex->current_token();

			node* new_node = new node(node_type::GOTO, name_goto);

			_lex->next_token();
			return new_node;
		}

		if (_lex->current_token() == "конец")
		{
			node* new_node = new node(node_type::RET, "");

			_lex->next_token();
			if (_lex->current_token() != ";")
			{
				message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
				throw Exception{ message };
			}

			return new_node;
		}
		
		if (_lex->current_token() == "если")
		{
			_lex->next_token();
			node* if_statment_node = if_statment();

			count_condition++;
			//cout << "кол-во 'если':" << count_condition << '\n';
			return if_statment_node;
		}

		if (_lex->current_token() == "иначе")
		{
			count_condition--;
			if (count_condition < 0)
			{
				message = message + to_string(_lex->number_string) + ": " + "кол-во 'иначе' не совпадет с кол-ом 'если'";
				throw Exception{ message };
				//error("never count if - else");
			}

			_lex->next_token();
			node* else_statment_node = else_statment();

			return else_statment_node;
		}
	}

	node* else_statment()
	{
		
		if (_lex->current_token() != "н")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось 'н'";
			throw Exception{ message };
			//error("'н' exepted");
		}

		count_lpar++;
		

		_lex->next_token();
		node* else_code_node = else_code();

		node* new_node = new node(node_type::ELSE, "", else_code_node);

		return new_node;
	}

	node* else_code()
	{
		node* operation_node = operation();

		_lex->next_token();
		if (_lex->current_token() != "к")
		{
			node* temp_operation = else_code();

			node* new_node = new node(node_type::ELSE_CODE, "", operation_node, temp_operation);
			return new_node;
		}

		count_lpar--;
		
		node* new_node = new node(node_type::ELSE_CODE, "", operation_node);
		return new_node;
	}

	node* if_statment()
	{
		if (_lex->current_token() != "(")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось '('";
			throw Exception{ message };
			//error("'(' exepted");
		}

		//условие
		_lex->next_token();
		node* condition_node = condition();


		_lex->next_token();
		if (_lex->current_token() != "н")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось 'н'";
			throw Exception{ message };
			//error("'н' exepted");
		}

		count_lpar++;
		
		
		_lex->next_token();
		node* if_code_node = if_code();


		node* new_node = new node(node_type::IF, "", condition_node, if_code_node);

		return new_node;
	}



	node* if_code()
	{
		node* operation_node = operation();

		_lex->next_token();
		if (_lex->current_token() != "к")
		{
			node* temp_operation = if_code();

			node* new_node = new node(node_type::IF_CODE, "", operation_node, temp_operation);
			return new_node;
		}

		count_lpar--;
		
		node* new_node = new node(node_type::IF_CODE, "", operation_node);
		return new_node;

	}

	node* condition()
	{
		node* cond1_node = first_condit();
		
		node* new_node_cond1 = new node(node_type::COND, "", cond1_node);

		_lex->next_token();
		if (_lex->current_token() != ")")
		{
			switch (_lex->current_token_type())
			{
			case token_type::AND:
			{
				_lex->next_token();
				node* temp_node = condition();

				node* new_node = new node(node_type::AND, "",new_node_cond1, temp_node);
				return new_node;
			}
			case token_type::OR:
			{
				_lex->next_token();
				node* temp_node = condition();

				node* new_node = new node(node_type::OR, "", new_node_cond1, temp_node);
				return new_node;
			}
			default:
			{
				message = message + to_string(_lex->number_string) + ": " + "недопустимая команда";
				throw Exception{ message };
				//error("undef");
				break;
			}
				
			}


		}

		
		return new_node_cond1;
	}

	

	node* first_condit()
	{
		node* value1 = name();

		//операция
		_lex->next_token();
		switch (_lex->current_token_type())
		{
		case token_type::AND:
		{
			_lex->next_token();
			node* value2 = value();

			node* new_node = new node(node_type::AND, "", value1, value2);
			return new_node;
		}
		case token_type::COM:
		{
			string compare = _lex->current_token();

			_lex->next_token();
			node* value2 = value();

			node* new_node = new node(node_type::COMPARE, compare, value1, value2);
			return new_node;
		}
		case token_type::OR:
		{
			_lex->next_token();
			node* value2 = value();
			node* new_node = new node(node_type::OR, "", value1, value2);
			return new_node;
		}
		default:
			break;
		}
	}

	node* action()
	{
		node* operand1 = name();

		_lex->next_token();
		if (_lex->current_token() != ";")
		{
			//операции
			if (_lex->current_token() == "(")
			{
				_lex->next_token();
				
				//вызов функции без параметров
				if (_lex->current_token() == ")")
				{

					_lex->next_token();
					if (_lex->current_token() != ";")
					{
						message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
						throw Exception{ message };
						//error("';' exepted2");
					}

					node* new_node = new node(node_type::CALL, "", operand1);
					return new_node;
				}

				//вызов функции с параметрами
				else
				{
					node* parametr_node = parametr();

					_lex->next_token();
					if (_lex->current_token() != ";")
					{
						message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
						throw Exception{ message };
						//error("';' exepted2");
					}

					node* new_node = new node(node_type::CALL, "",  operand1, parametr_node);
					return new_node;
				}
			}

			switch (_lex->current_token_type())
			{
			case token_type::AND:
			{
				_lex->next_token();
				node* operand2 = value();

				_lex->next_token();
				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
					//error("';' exepted2");
				}

				node* new_node = new node(node_type::AND, "", operand1, operand2);
				return new_node;
			}
			case token_type::ASSGN:
			{
				_lex->next_token();
				node* operand2 = value();

				//параметры
				_lex->next_token();
				if (_lex->current_token() == "(")
				{
					_lex->next_token();
					if (_lex->current_token() == ")")
					{
						_lex->next_token();
						//функция без параметров
						node* funct_node = new node(node_type::EXPR, "", operand2);

						if (_lex->current_token() != ";")
						{
							message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
							throw Exception{ message };
							//error("';' exepted");
						}

						node* new_node = new node(node_type::ASSGN, "", operand1, funct_node);
						return new_node;
					}

					else
					{
						node* parametr_node = parametr();

						node* function_node = new node(node_type::EXPR, "", operand2, parametr_node);

						node* assgn_node = new node(node_type::ASSGN, "", operand1, function_node);

						_lex->next_token();
						if (_lex->current_token() != ";")
						{
							message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
							throw Exception{ message };
							//error("exepted ';'");
						}

						return assgn_node;
					}
				}

				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
					
				}

				node* new_node = new node(node_type::ASSGN, "", operand1, operand2);
				return new_node;
			}
			case token_type::MINUS:
			{
				_lex->next_token();
				node* operand2 = value();

				_lex->next_token();
				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
				}

				node* new_node = new node(node_type::SUB, "", operand1, operand2);
				return new_node;
			}
			case token_type::NOT:
			{
				_lex->next_token();
				node* operand2 = value();

				_lex->next_token();
				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
				}

				node* new_node = new node(node_type::NOT, "", operand1, operand2);
				return new_node;
			}
			case token_type::OR:
			{
				_lex->next_token();
				node* operand2 = value();

				_lex->next_token();
				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
				}

				node* new_node = new node(node_type::OR, "", operand1, operand2);
				return new_node;
			}
			case token_type::PLUS:
			{
				_lex->next_token();
				node* operand2 = value();

				_lex->next_token();
				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
					//error("';' exepted3");
				}

				node* new_node = new node(node_type::ADD, "", operand1, operand2);
				return new_node;
			}
			case token_type::SHIFT:
			{
				_lex->next_token();
				node* operand2 = value();

				_lex->next_token();
				if (_lex->current_token() != ";")
				{
					message = message + to_string(_lex->number_string) + ": " + "ожидалось ';'";
					throw Exception{ message };
				}

				node* new_node = new node(node_type::SHIFT, "", operand1, operand2);
				return new_node;
			}
			default:
				break;
			}
		}
		
		
		//_lex->prev_token();
		return operand1;
	}

	node* name()
	{
		string value_expr = _lex->current_token();
		if (_lex->current_token_type() == token_type::ID)
		{
			node* new_node = new node(node_type::ID, value_expr);
			return new_node;
		}
		else
		{
			_lex->next_token();
			
			message = message + to_string(_lex->number_string) + ": " + "ожидалось имя";
			throw Exception{ message };
			//error("identification exepted");
		}
	}

	node* define()
	{
		node* macros_node = macros();

		_lex->next_token();
		if (_lex->current_token() != "н")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось 'н'";
			throw Exception{ message };
			//error("'н' exepted");
		}

		_lex->next_token();
		node* preproc_node = preproc();
		
		_lex->next_token();
		if (_lex->current_token() != "к")
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось 'к'";
			throw Exception{ message };
			//error("'к' exepted");
		}

		node* new_node = new node(node_type::DEFINE, "", macros_node, preproc_node);
		return new_node;

	}

	node* preproc()
	{
		if (_lex->current_token_type() == token_type::MINUS)
		{
			//_lex->next_token();
			node* value_node = value();
			node* new_node = new node(node_type::PREPROC, "-", value_node);
			return new_node;
		}

		node* value_node = value();
		node* new_node = new node(node_type::PREPROC, "", value_node);
		return new_node;
	}

	node* macros()
	{
		node* value_node = name();

		_lex->next_token();
		if (_lex->current_token() == "(")
		{
			//параметры
			_lex->next_token();
			if (_lex->current_token() == ")")
			{
				message = message + to_string(_lex->number_string) + ": " + "ожидались параметры";
				throw Exception{ message };
			}
			node* parametr_node = parametr();

			node* new_node = new node(node_type::MACROS, "", value_node, parametr_node);
			return new_node;
		}


		_lex->prev_token();
		node* new_node = new node(node_type::MACROS, "", value_node);
		return new_node;
	}

	node* parametr()
	{
		node* value_node = value();

		_lex->next_token();
		if (_lex->current_token() != ")")
		{
			_lex->next_token();
			node* temp_node = parametr();

			node* new_node = new node(node_type::PARAMETR, "", value_node, temp_node);
			return new_node;
		}

		node* new_node = new node(node_type::PARAMETR, "", value_node);

		return new_node;
	}

	node* value()
	{
		string value_expr = _lex->current_token();
		if (_lex->current_token_type() == token_type::ID)
		{
			node* new_node = new node(node_type::ID, value_expr);
			return new_node;
		}

		else if (_lex->current_token_type() == token_type::NUMBER)
		{
			node* new_node = new node(node_type::NUMBER, value_expr);
			return new_node;
		}

		else if (_lex->current_token_type() == token_type::MINUS)
		{
			_lex->next_token();
			string value = "-"+_lex->current_token();
			node* new_node = new node(node_type::ID, value);
			return new_node;
		}
		else
		{
			message = message + to_string(_lex->number_string) + ": " + "ожидалось какае-то значение";
			throw Exception{ message };
		}
	}

	void error(const string& message)
	{
		cout << "Error! " << _lex->current_token() << " " << message << '\n';
		throw::logic_error(message);
	}

public:
	void parse()
	{
		try
		{
			_lex->split();
			//_lex->print();
			_ast->tree = code();
			_ast->print();

			_all_triads->create_obj(_ast->tree);
			_all_triads->print_triads();
		}
		catch (Exception ex)
		{
			cout << ex.getMessage() << '\n';
		}
		
		
	}
};