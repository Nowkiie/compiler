#pragma once
#include <iostream>
#include <string>

using namespace std;

enum class node_type
{
	CODE,
	PROC,
	PROC_CODE,
	IF_CODE,
	COND,
	ELSE_CODE,

	//директории 
	DEFINE,
	PREPROC,
	MACROS,
	PARAMETR,
	EXPR,
	RET,
	RETURN,

	//операции
	SUB,
	ASSGN,
	ADD,
	MULT,
	DIV,
	AND,
	METKA,
	CALL,
	OR,
	NOT,
	SHIFT,
	GOTO,
	IF,
	COMPARE,
	ELSE,

	//значения
	ID,
	NUMBER,

};

class node
{
public:
	string value;
	node_type type;

	node* operand1;
	node* operand2;


	node(node_type type, const string& value = "",
		node* operand1 = nullptr, node* operand2 = nullptr)
	{
		this->type = type;
		this->value = value;
		this->operand1 = operand1;
		this->operand2 = operand2;
	}
};

class ast
{
public :
	node* tree;

public:
	ast()
	{
		tree = nullptr;
	}

	void print_recursive(node* current_node, size_t level)
	{
		if (current_node == nullptr) return;

		for (int i = 0; i < level; i++)
		{
			cout << " ";
		}
		cout << "+-";
		
		switch (current_node->type)
		{
		case node_type::ADD:
		{
			cout << "ADD";
			break;
		}
		case node_type::AND:
		{
			cout << "AND";
			break;
		}
		case node_type::ASSGN:
		{
			cout << "ASSGN";
			break;
		}
		case node_type::CALL :
		{
			cout << "CALL";
			break;
		}
		case node_type::CODE:
		{
			cout << "CODE";
			break;
		}
		case node_type::COMPARE:
		{
			cout << "COMPARE";
			cout << "(" << current_node->value << ")";
			break;
		}
		case node_type::COND:
		{
			cout << "COND";
			break;
		}
		case node_type::DEFINE:
		{
			cout << "DEFINE";
			break;
		}
		case node_type::DIV:
		{
			cout << "DIV";
			break;
		}
		case node_type::ELSE:
		{
			cout << "ELSE";
			break;
		}
		case node_type::ELSE_CODE:
		{
			cout << "ELSE CODE";
			break;
		}
		case node_type::EXPR:
		{
			cout << "EXPR";
			break;
		}
		case node_type::GOTO:
		{
			cout << "GOTO";
			cout << "(" << current_node->value << ")";
			break;
		}
		case node_type::ID:
		{
			cout << "ID";
			cout << "(" << current_node->value << ")";
			break;
		}
		case node_type::IF:
		{
			cout << "IF";
			break;
		}
		case node_type::IF_CODE:
		{
			cout << "IF CODE";
			break;
		}
		case node_type::MACROS:
		{
			cout << "MACROS";
			break;
		}
		case node_type::METKA:
		{
			cout << "METKA";
			cout << "(" << current_node->value << ")";
			break;
		}
		case node_type::MULT:
		{
			cout << "MULT";
			break;
		}
		case node_type::NOT:
		{
			cout << "NOT";
			break;
		}
		case node_type::NUMBER:
		{
			cout << "NUMBER";
			cout << "(" << current_node->value << ")";
			break;
		}
		case node_type::OR:
		{
			cout << "OR";
			break;
		}
		case node_type::PARAMETR:
		{
			cout << "PARAMETR";
			break;
		}
		case node_type::PREPROC:
		{
			cout << "PREPROC";
			break;
		}
		case node_type::PROC:
		{
			cout << "PROC";
			cout<<"(" << current_node->value << ")";
			break;
		}
		case node_type::PROC_CODE:
		{
			cout << "PROC_CODE";
			break;
		}
		case node_type::RET:
		{
			cout << "RET";
			break;
		}
		case node_type::RETURN:
		{
			cout << "RETURN";
			break;
		}
		case node_type::SHIFT:
		{
			cout << "SHIFT";
			break;
		}
		case node_type::SUB:
		{
			cout << "SUB";
			break;
		}
		default:
			break;
		}
		cout << '\n';

		print_recursive(current_node->operand1, level + 1);
		print_recursive(current_node->operand2, level + 1);
	}


	void print()
	{
		print_recursive(tree, 0);

	}
};