#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <format>
#include "Hex_code.h"
#include "Name_func_table.h"
#include "Define_table.h"

using namespace std;


class hex_code_table
{
	vector <hex_code*> _codes;

	char DigitToHex(int N)
	{
		switch (N)
		{
		case 0: return '0'; break;
		case 1: return '1'; break;
		case 2: return '2'; break;
		case 3: return '3'; break;
		case 4: return '4'; break;
		case 5: return '5'; break;
		case 6: return '6'; break;
		case 7: return '7'; break;
		case 8: return '8'; break;
		case 9: return '9'; break;
		case 10: return 'A'; break;
		case 11: return 'B'; break;
		case 12: return 'C'; break;
		case 13: return 'D'; break;
		case 14: return 'E'; break;
		case 15: return 'F'; break;
		default:
			return NULL;
			break;
		}
	}

	string to_hex_2(int number)
	{
		string res = "";
		int x;
		while (number > 0)
		{
			x = number % 16;
			number = number / 16;
			if (x < 16) res = DigitToHex(x) + res;
		}

		return res;
	}
	
	string to_hex(int number)
	{
		string res = "";
		int x;
		while (number > 0)
		{
			x = number % 16;
			number = number / 16;
			if (x < 16) res = DigitToHex(x) + res;
		}
		int count_number = res.length();
		//cout << count_number<<'\n';
		switch (count_number)
		{
		case 0:
		{
			return "0000";
			break;
		}
		case 1:
		{
			return "000" + res;
			break;
		}
		case 2:
		{
			return "00" + res;
			break;
		}
		case 3:
		{
			return "0" + res;
			break;
		}
		default:
			break;
		}
		
	}

public:
	hex_code_table()
	{

	}

	void generate_hex_code(vector <name_func*>& names, vector <triad*>& _all_triads, define_table* _defs)
	{
		hex_code* new_hex;
		for (auto& name : names)
		{
			if (name->get_name() == "векторы_прерыв")
			{
				
				new_hex = new hex_code("0c", "94", "61", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "5d", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "73", "00");
				_codes.push_back(new_hex);


			}

			if (name->get_name() == "лин_конец")
			{
				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("24", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("27", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("2a", "00", "", "");
				_codes.push_back(new_hex);

				/*new_hex = new hex_code("04", "07", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);*/

				/*new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);*/
			}

			if (name->get_name() == "порт_вых")
			{
				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("25", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("28", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("2b", "00", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "порт_вх")
			{
				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				

				new_hex = new hex_code("23", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("26", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("29", "00", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "цифр_пин_порт")
			{
				new_hex = new hex_code("04", "04", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("04", "04", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("04", "04", "", "");
				_codes.push_back(new_hex);


				new_hex = new hex_code("04", "04", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("02", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("02", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("02", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("03", "03", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("03", "03", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("03", "03", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "цифр_пин_бит_маска")
			{
				new_hex = new hex_code("01", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("04", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("10", "20", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("40", "80", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("04", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("10", "20", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("04", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("10", "20", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "цифр_пин_таймер")
			{
				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "02", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "03", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("04", "07", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "иниц")
			{
				new_hex = new hex_code("11", "24", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("1f", "be", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "ef", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d8", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("de", "bf", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cd", "bf", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "иниц_данных")
			{
				new_hex = new hex_code("21", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a0", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "c0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("1d", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a9", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b2", "07", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e1", "f7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "a7", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "94", "63", "02");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "нет_прерыв")
			{
				new_hex = new hex_code("0c", "94", "00", "00");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "таймер")
			{
				new_hex = new hex_code("83", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("28", "f4", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("99", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("82", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a9", "f0", "", "");
				_codes.push_back(new_hex);
				
				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("87", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a9", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c9", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "f4", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "80", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "7d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("03", "c0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "80", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "77", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "80", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "77", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "bd", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "7d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("fb", "cf", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "b0", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "77", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "b0", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "b0", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "7d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "cf", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "чт÷ифр")
			{
				new_hex = new hex_code("cf", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("28", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("30", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e2", "55", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e6", "56", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ea", "57", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cc", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a1", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "11", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "75", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ec", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f0", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ee", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "1f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e4", "58", "", "");
				_codes.push_back(new_hex);


				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a5", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ec", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ed", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("09", "f4", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("fa", "cf", "", "");
				_codes.push_back(new_hex);

			}

			if (name->get_name() == "зап÷ифр")
			{
				new_hex = new hex_code("1f", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("28", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("30", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e2", "55", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e6", "56", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f9", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ea", "57", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cc", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a9", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("16", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "11", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "75", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ec", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f0", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ee", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "1f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ee", "58", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a5", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "b7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f8", "94", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ec", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("11", "11", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "c0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d0", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("de", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("dc", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "bf", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("1f", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("de", "2b", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f8", "cf", "", "");
				_codes.push_back(new_hex);

				
			}

			if (name->get_name() == "пин–ежим")
			{
				new_hex = new hex_code("cf", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("fc", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e6", "56", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("24", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8a", "57", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("fc", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d1", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("99", "1f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("fc", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e8", "59", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a5", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("fc", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ee", "58", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "4f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c5", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d4", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("61", "11", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "c0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "b7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f8", "94", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8c", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e2", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e0", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8e", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8c", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("28", "81", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e2", "23", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a8", "83", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "bf", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "b7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f8", "94", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ec", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e2", "2b", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ec", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "bf", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f6", "cf", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "–егистр¬ых")
			{
				new_hex = new hex_code("cf", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d8", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c8", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("6d", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("61", "70", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8d", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d6", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("61", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8b", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("60", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8b", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c1", "50", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "f7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);


			}

			if (name->get_name() == "–егистр¬х")
			{
				new_hex = new hex_code("1f", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d0", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c0", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("10", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("61", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("86", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("85", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "9e", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0c", "2e", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "c0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0a", "94", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ea", "f7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("18", "2b", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("60", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("86", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("21", "96", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c8", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d1", "05", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("59", "f7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("1f", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "микросекунды")
			{
				new_hex = new hex_code("3f", "b7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f8", "94", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("05", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "91", "06", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("A0", "91", "07", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b0", "91", "08", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("26", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a8", "9b", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("05", "c0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("2f", "3f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("19", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "96", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("3f", "bf", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ba", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a9", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("98", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "27", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("bc", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cd", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("62", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("71", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("91", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("42", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("66", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("77", "1f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "1f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("99", "1f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("4a", "95", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d1", "f7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "задержка")
			{
				new_hex = new hex_code("8f", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("af", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("bf", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ef", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "db", "00");
				_codes.push_back(new_hex);

				

				new_hex = new hex_code("4b", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("5c", "01", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "ee", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c8", "2e", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("83", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d8", "2e", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e1", "2c", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f1", "2c", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "db", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("68", "19", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("79", "09", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8a", "09", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9b", "09", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("68", "3e", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("73", "40", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "05", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("91", "05", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a8", "f3", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("21", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c2", "1a", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d1", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e1", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f1", "08", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "ee", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "0e", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("83", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("98", "1e", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a1", "1c", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "1c", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("c1", "14", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("d1", "04", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("e1", "04", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("f1", "04", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("29", "f7", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ff", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("ef", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("df", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("cf", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("bf", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("af", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "95", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "вектор_16")
			{
				new_hex = new hex_code("1f", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0f", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0f", "b6", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0f", "92", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("11", "24", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("2f", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("3f", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("af", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("bf", "93", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "01", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "91", "02", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a0", "91", "03", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b0", "91", "04", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("30", "91", "00", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "96", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("23", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("23", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("2d", "37", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("26", "e8", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("23", "0f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("02", "96", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("20", "93", "00", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "01", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "93", "02", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a0", "93", "03", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b0", "93", "04", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "05", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "91", "06", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a0", "91", "07", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b0", "91", "08", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "96", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b1", "1d", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "05", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("90", "93", "06", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("a0", "93", "07", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("b0", "93", "08", "01");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("00", "00", "", "");
				_codes.push_back(new_hex);

				

				new_hex = new hex_code("bf", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("af", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("9f", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("8f", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("3f", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("2f", "91", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0f", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0f", "be", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0f", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("1f", "90", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("18", "95", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "иниц_глав")
			{
				new_hex = new hex_code("78", "94", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("82", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "bd", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "bd", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("85", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("82", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("85", "bd", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("85", "b5", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("85", "bd", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "6e", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "6e", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("10", "92", "81", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "81", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("82", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "81", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "81", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "81", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "80", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "80", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "b1", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "b1", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "b0", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "b0", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("84", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("82", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "60", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "91", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "68", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("80", "93", "7a", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("10", "92", "c1", "00");
				_codes.push_back(new_hex);


			}

			

			if (name->get_name() == "код_основ")
			{	
				int count_def = _defs->size();

				for (auto& triad : _all_triads)
				{
					string operation=triad->get_operation();
					if (operation == "ldi")
					{
						if (count_def == 0)
						{
							new_hex = new hex_code("c0", "e0", "", "");
							_codes.push_back(new_hex);

							new_hex = new hex_code("d0", "e0", "", "");
							_codes.push_back(new_hex);

						}
						int operand1 = triad->get_num_reg();
						int command1 = operand1 - 16;
						string command = to_string(command1);

						int operand2 = triad->get_num_or_reg();
						if (operand2 < 10)
						{
							command += to_string(operand2);
						}
						else
						{
							switch (operand2)
							{
							case 10:
							{
								command += "a";
								break;
							}
							case 11:
							{
								command += "b";
								break;
							}
							case 12:
							{
								command += "c";
								break;
							}
							case 13:
							{
								command += "d";
								break;
							}
							case 14:
							{
								command += "e";
								break;
							}
							case 15:
							{
								command += "f";
								break;
							}

							default:
							{
								throw Exception{ "слишком большое число" };
								break;
							}
								
							}
						}

						cout << command << ' ' << "0e\n";

						new_hex = new hex_code(command, "e0");
						_codes.push_back(new_hex);
					}

					if (operation == "call")
					{
						int adress_call = triad->get_num_reg();
						if (adress_call == 398) //digitalwrite
						{
							
								
							cout << "0e 94 c7 00\n";
							new_hex = new hex_code("0e", "94", "c7", "00");
							_codes.push_back(new_hex);
						}

						if (adress_call == 490) //pinMode
						{
							count_def--;
							new_hex = new hex_code("0e", "94", "f5", "00");
							_codes.push_back(new_hex);
							cout << "0e 94 f5 00\n";
						}

						if (adress_call == 316) //digitalRead
						{
							new_hex = new hex_code("0e", "94", "9e", "00");
							_codes.push_back(new_hex);
						}

						if (adress_call == 588) //shiftOut
						{
							new_hex = new hex_code("0e", "94", "26", "01");
							_codes.push_back(new_hex);

							cout << "0e 94 26 01\n";
						}

						if (adress_call == 634) //shiftIn
						{
							new_hex = new hex_code("0e", "94", "3d", "01");
							_codes.push_back(new_hex);
						}

					}

					if (operation == "nop")
					{
						new_hex = new hex_code("00", "00", "", "");
						_codes.push_back(new_hex);
					}

					if (operation == "cpi")
					{
						cout << "cpi: ";
						int operand1 = triad->get_num_reg();
						int command1 = operand1 - 16;
						string command = to_string(command1);

						int operand2 = triad->get_num_or_reg();
						int command2 = operand2;
						command += to_string(command2);


						//cout << command << "  30\n";

						new_hex = new hex_code(command, "30");
						_codes.push_back(new_hex);
					}

					if (operation == "mov")
					{
						cout << "mov: ";
						int operand1 = triad->get_num_reg();
						int command1 = operand1 - 16;
						string command = to_string(command1);

						int operand2 = triad->get_num_or_reg();
						int command2 = operand2 - 16;
						command += to_string(command2);

						cout << command << " 2f\n";

						new_hex = new hex_code(command, "2f");
						_codes.push_back(new_hex);
					}

					if (operation == "breq")
					{
						int operand = triad->get_num_reg();

						if (operand == 4)
						{
							new_hex = new hex_code("11", "f0", "", "");
							_codes.push_back(new_hex);
						}
					}

				}

				//2
				/*new_hex = new hex_code("61", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "f5", "00");
				_codes.push_back(new_hex);*/

				//3
				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("80", "e1", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);


				////4
				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("81", "e1", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////5
				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("87", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////6
				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("86", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////7
				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("85", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////8
				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("84", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////9
				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8c", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////10
				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8d", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				////11
				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8b", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "f5", "00");
				//_codes.push_back(new_hex);

				
				//loop
				



			/*	new_hex = new hex_code("80", "e1", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "9e", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("08", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("81", "e1", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "9e", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("18", "2f", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("61", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("01", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("09", "f0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("60", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("89", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);

				new_hex = new hex_code("61", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("11", "30", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("09", "f0", "", "");
				_codes.push_back(new_hex);*/

				/*new_hex = new hex_code("61", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("88", "e0", "", "");
				_codes.push_back(new_hex);

				new_hex = new hex_code("0e", "94", "c7", "00");
				_codes.push_back(new_hex);*/

				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8c", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("80", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "26", "01");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8c", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("87", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("87", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("86", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("84", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "3d", "01");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("18", "2f", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "3d", "01");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("84", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("60", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8c", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("81", "2f", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "26", "01");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("61", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("8c", "e0", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "c7", "00");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("20", "97", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("09", "f4", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("b8", "cf", "", "");
				//_codes.push_back(new_hex);

				//new_hex = new hex_code("0e", "94", "00", "00");
				//_codes.push_back(new_hex);

				new_hex = new hex_code("b5", "cf", "", "");
				_codes.push_back(new_hex);


				

			}

			if (name->get_name() == "выход")
			{
				new_hex = new hex_code("f8", "94", "", "");
				_codes.push_back(new_hex);
			}

			if (name->get_name() == "стоп_прогр")
			{
				new_hex = new hex_code("ff", "cf", "", "");
				_codes.push_back(new_hex);
			}
		}
	}


	void print_hex_code()
	{
		ofstream outf ("code.hex");
		
		string result;
		int number = 0;
		int sum = 0;
		int shift = 0;

		int shift1;
		int shift2;

		for (auto& hexs : _codes)
		{
			result = result + hexs->get_hc1();
			sum = sum + stoi(hexs->get_hc1(), 0, 16);

			number += 1;

			if (number >= 16)
			{
				ofstream shift_temp("shift.txt");
				shift_temp << to_hex(shift) << '\n';
				shift_temp.close();

				if (shift >= 256)
				{
					shift1 = shift / 256;
					shift2 = shift - 256;

				}
				else
				{
					shift1 = 0;
					shift2 = shift;
				}



				int check_sum = ~(sum + 16 + shift1 + shift2) + 1;
				ofstream temp("kontr_sum.txt");
				temp << hex << check_sum << '\n';
				temp.close();
				string k_sum;
				string hex_str;

				ifstream inf("kontr_sum.txt");
				if (inf.is_open())
				{
					while (getline(inf, k_sum))
					{
						//cout << to_hex(shift) << '\n';
						hex_str = ":10" + to_hex(shift) + "00" + result + k_sum[k_sum.length() - 2] + k_sum[k_sum.length() - 1] + '\n';
					}
				}

				inf.close();


				outf << hex_str;


				result = "";
				shift += 16;
				number = 0;
				sum = 0;
			}

			result = result + hexs->get_hc2();
			sum = sum + stoi(hexs->get_hc2(), 0, 16);

			number += 1;
			
			if (number >= 16)
			{
				ofstream shift_temp("shift.txt");
				shift_temp << to_hex(shift) << '\n';
				shift_temp.close();

				if (shift >= 256)
				{
					shift1 = shift / 256;
					shift2 = shift - 256;

				}
				else
				{
					shift1 = 0;
					shift2 = shift;
				}



				int check_sum = ~(sum + 16 + shift1 + shift2) + 1;
				ofstream temp("kontr_sum.txt");
				temp << hex << check_sum << '\n';
				temp.close();
				string k_sum;
				string hex_str;

				ifstream inf("kontr_sum.txt");
				if (inf.is_open())
				{
					while (getline(inf, k_sum))
					{
						//cout << to_hex(shift) << '\n';
						hex_str = ":10" + to_hex(shift) + "00" + result + k_sum[k_sum.length() - 2] + k_sum[k_sum.length() - 1] + '\n';
					}
				}

				inf.close();


				outf << hex_str;


				result = "";
				shift += 16;
				number = 0;
				sum = 0;
			}

			if (hexs->get_hc3() != "")
			{
				result = result + hexs->get_hc3();
				sum = sum + stoi(hexs->get_hc3(), 0, 16);

				result = result + hexs->get_hc4();
				sum = sum + stoi(hexs->get_hc4(), 0, 16);

				number += 2;
			}




			if (number >= 16)
			{
				ofstream shift_temp("shift.txt");
				shift_temp << to_hex(shift) << '\n';
				shift_temp.close();

				if (shift >= 256)
				{
					shift1 = shift / 256;
					shift2 = shift - 256;

				}
				else
				{
					shift1 = 0;
					shift2 = shift;
				}



				int check_sum = ~(sum + 16 + shift1 + shift2) + 1;
				ofstream temp("kontr_sum.txt");
				temp << hex << check_sum << '\n';
				temp.close();
				string k_sum;
				string hex_str;

				ifstream inf("kontr_sum.txt");
				if (inf.is_open())
				{
					while (getline(inf, k_sum))
					{
						//cout << to_hex(shift) << '\n';
						hex_str = ":10" + to_hex(shift) + "00" + result + k_sum[k_sum.length() - 2] + k_sum[k_sum.length() - 1] + '\n';
					}
				}

				inf.close();


				outf << hex_str;


				result = "";
				shift += 16;
				number = 0;
				sum = 0;
			}
		}

		if (shift >= 256)
		{
			shift1 = shift / 256;
			shift2 = shift - 256;

		}
		else
		{
			shift1 = 0;
			shift2 = shift;
		}

		int check_sum = ~(sum + number + shift1+shift2) + 1;
		ofstream temp("kontr_sum.txt");

		temp << hex << check_sum << '\n';
		temp.close();
		string k_sum;
		string hex_str;
		ifstream inf("kontr_sum.txt");
		if (inf.is_open())
		{
			while (getline(inf, k_sum))
			{
				//cout << number << '\n';
				hex_str =":0" +to_hex_2(number) + to_hex(shift) + "00" + result + k_sum[k_sum.length() - 2] + k_sum[k_sum.length() - 1] + '\n';
			}
		}

		inf.close();

		outf << hex_str;

		outf.close();
	}

	
};