#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Triad.h"
#include "AST.h"
#include "Name_func_table.h"
#include "Hex_code_table.h"
#include "Define_table.h"
#include "Exception.h"

using namespace std;

class triadList
{
	define_table* _defs;
	vector <triad*> _all_triads;
	vector <triad*> _temp_triads;
	vector <name_func*> _names_func;
	hex_code_table* _hexes;

	int number_reg_for_ans = 16;
	int number_command = 0;
	bool for_param = true;
	int number_operand = 0;
	void reverse_triad(vector <triad*>& _all_triads, vector <triad*>& _temp_triads)
	{
		reverse(begin(_temp_triads), end(_temp_triads));
		_all_triads.insert(_all_triads.end(), _temp_triads.begin(), _temp_triads.end());
		_temp_triads.clear();

	}

public:
	triadList()
	{
		_defs = new define_table();
		_hexes = new hex_code_table();
	}

	void generate_triad(node* current_node)
	{
		

		if (current_node == nullptr) return;

		switch (current_node->type)
		{
		case node_type::DEFINE:
		{
			node* macros = current_node->operand1;
			string name_macros = macros->operand1->value;

			int number_pin=0;
			node* preproc = current_node->operand2;
			if (preproc->operand1->type == node_type::NUMBER)
			{
				number_pin = stoi(preproc->operand1->value, 0);
			}
			else
			{
				string op = preproc->operand1->value;
				if (op == "ј0")
				{
					number_pin = 14;
				}

				if (op == "ј1")
				{
					number_pin = 15;
				}

				if (op == "ј2")
				{
					number_pin = 16;
				}

				if (op == "ј3")
				{
					number_pin = 17;
				}

			}
			
			def* new_def = new def(name_macros, number_pin);
			_defs->push_defs(new_def);

			break;
		}
		case node_type::EXPR:
		{
			string name_call = current_node->operand1->value;

			if (name_call == "чт÷ифр")
			{
				triad* new_triad = new triad("call", 0x13c, 0);
				_temp_triads.push_back(new_triad);

				for_param = true;
			}

			if (name_call == "–егистр¬х")
			{
				//number_reg_for_ans++;

				triad* new_triad = new triad("call", 0x27a, 0);
				_temp_triads.push_back(new_triad);



				for_param = false;
			}

			break;
		}
		case node_type::CALL:
		{
			reverse_triad(_all_triads, _temp_triads);
			string name_call = current_node->operand1->value;
			if (name_call == "зап÷ифр")
			{
				triad* new_triad = new triad("call", 0x18e, 0);
				_temp_triads.push_back(new_triad);

				for_param = true;
			}

			

			if (name_call == "–егистр¬ых")
			{
				
				node* param = current_node->operand2->operand2->operand2->operand2->operand1;

				if (param->type == node_type::NUMBER)
				{
					triad* new_triad = new triad("ldi", 24, stoi(param->value, 0));
					_all_triads.push_back(new_triad);
				}
				else
				{
					int number = _defs->get_number_by_name(param->value);

					triad* new_triad = new triad("mov", 24, number);
					_all_triads.push_back(new_triad);

				}
				

				triad* new_triad = new triad("call", 0x24c, 0);
				_all_triads.push_back(new_triad);

				

				for_param = false;
			}

			
			
			if (name_call == "пин–ежим")
			{
				triad* new_triad = new triad("call", 0x1ea, 0);
				_temp_triads.push_back(new_triad);

				for_param = true;
			}
			
			

			break;
		}
		case node_type::PARAMETR:
		{
			


			string value_parametr = current_node->operand1->value;
			if (value_parametr == "¬џ—ќ " || value_parametr == "¬џ’")
			{
				triad* new_triad = new triad("ldi", 22, 01);
				_temp_triads.push_back(new_triad);

				
			}

			else if (value_parametr == "Ќ»« " || value_parametr == "¬’")
			{
				triad* new_triad = new triad("ldi", 22, 00);
				_temp_triads.push_back(new_triad);

				
			}

			else
			{
				if (for_param)
				{
					int number = _defs->get_number_by_name(value_parametr);

					if (number == -1)
					{
						string message = "неизвестный параметр: " + value_parametr;
						throw Exception{ message };
					}
					else
					{

						triad* new_traid = new triad("ldi", 24, number);
						_temp_triads.push_back(new_traid);
					}
				}
				

				
			}

			

			break;
		}
		case node_type::ELSE_CODE:
		{
			
			/*triad* new_traid = new triad("nop", 0, 0);
			_temp_triads.push_back(new_traid);*/

			int goto_adress = _temp_triads.size()+1;
			cout << goto_adress << '\n';

			triad* new_traid = new triad("breq", goto_adress, 0);
			_temp_triads.push_back(new_traid);

			reverse_triad(_all_triads, _temp_triads);

			break;
		}
		case node_type::COMPARE:
		{
			reverse_triad(_all_triads, _temp_triads);
			node* operand = current_node;

			string op2 = operand->operand2->value;
			if (op2 == "¬џ—ќ ")
			{
				string name_compare = operand->operand1->value;
				int number_reg_compare = _defs->get_number_by_name(name_compare);

				triad* new_traid = new triad("cpi", number_reg_compare, 1);
				_temp_triads.push_back(new_traid);
			}
			
			//запуск счетчика команд до else
			

			break;
		}
		case node_type::ASSGN:
		{
			string name = current_node->operand1->value;
			reverse_triad(_all_triads, _temp_triads);

			if (current_node->operand2->type == node_type::EXPR)
			{
				triad* new_traid = new triad("mov", number_reg_for_ans, 24);
				_temp_triads.push_back(new_traid);

				def* new_def = new def(name, number_reg_for_ans);
				_defs->push_defs(new_def);

				number_reg_for_ans++;
			}
			
			if (current_node->operand2->type == node_type::NUMBER)
			{
				int number = stoi(current_node->operand2->value);
				def* new_def = new def(name, number_reg_for_ans);
				_defs->push_defs(new_def);

				triad* new_traid = new triad("ldi", number_reg_for_ans, number);
				_temp_triads.push_back(new_traid);
			}

			break;
		}
		default:
			break;
		}

		generate_triad(current_node->operand1);
		generate_triad(current_node->operand2);
	}

	void triad_for_circle()
	{
		reverse_triad(_all_triads, _temp_triads);

		triad*  new_triad = new triad("sbiw", 28, 00);
		_all_triads.push_back(new_triad);

		new_triad = new triad("brne", 2, 0);
		_all_triads.push_back(new_triad);

		new_triad = new triad("rjmp",  -144, 0);
		_all_triads.push_back(new_triad);

		new_triad = new triad("call", 0, 00);
		_all_triads.push_back(new_triad);

		new_triad = new triad("rjmp", -150, 00);
		_all_triads.push_back(new_triad);
	}

	void create_names_func()
	{
		name_func* new_name;

		new_name = new name_func("векторы_прерыв");
		_names_func.push_back(new_name);

		new_name = new name_func("лин_конец");
		_names_func.push_back(new_name);

		new_name = new name_func("порт_вых");
		_names_func.push_back(new_name);

		new_name = new name_func("порт_вх");
		_names_func.push_back(new_name);

		new_name = new name_func("цифр_пин_порт");
		_names_func.push_back(new_name);

		new_name = new name_func("цифр_пин_бит_маска");
		_names_func.push_back(new_name);

		new_name = new name_func("цифр_пин_таймер");
		_names_func.push_back(new_name);

		new_name = new name_func("иниц");
		_names_func.push_back(new_name);

		new_name = new name_func("иниц_данных");
		_names_func.push_back(new_name);

		new_name = new name_func("нет_прерыв");
		_names_func.push_back(new_name);

		new_name = new name_func("таймер");
		_names_func.push_back(new_name);

		new_name = new name_func("чт÷ифр");
		_names_func.push_back(new_name);

		new_name = new name_func("зап÷ифр");
		_names_func.push_back(new_name);

		new_name = new name_func("пин–ежим");
		_names_func.push_back(new_name);

		new_name = new name_func("–егистр¬ых");
		_names_func.push_back(new_name);

		new_name = new name_func("–егистр¬х");
		_names_func.push_back(new_name);

		new_name = new name_func("вектор_16");
		_names_func.push_back(new_name);

		new_name = new name_func("иниц_глав");
		_names_func.push_back(new_name);

		new_name = new name_func("код_основ");
		_names_func.push_back(new_name);

		new_name = new name_func("выход");
		_names_func.push_back(new_name);

		new_name = new name_func("стоп_прогр");
		_names_func.push_back(new_name);

	}

	void create_obj(node* current_node)
	{

		generate_triad(current_node);
		reverse_triad(_all_triads, _temp_triads);

		cout << "def\n";
		_defs->print_def();

		create_names_func();

		//_names_func->print_name();
		_hexes->generate_hex_code(_names_func, _all_triads, _defs);
		_hexes->print_hex_code();
		ofstream outf("code.hex", ios::app);
		outf << ":00000001FF" << '\n';
		outf.close();
	}


	void print_triads()
	{
		for (auto& triad : _all_triads)
		{
			cout << triad->get_operation() << ' ';
			cout << triad->get_num_reg() << ' ';
			cout << triad->get_num_or_reg() << '\n';
		}
	}
};