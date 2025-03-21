#include <iostream>
#include <string>
#include "Parser.h"

int main()
{
	setlocale(LC_ALL, "rus");
	string code = R"( 
определить пинƒиод н 8 к
определить пин¬ыкл н 3 к



главна€
н
	пин–ежим(пин¬ыкл, ¬’);
	пин–ежим(пинƒиод, ¬џ’);

	с1 = чт÷ифр(пин¬ыкл);
	если (с1 == ¬џ—ќ )
	н
	  зап÷ифр(пинƒиод, ¬џ—ќ );
	к
	иначе
	н
		зап÷ифр(пинƒиод, Ќ»« );
	к	
	
к

)";
	
	cout << code << '\n';
	
	parser pars(code);
	pars.parse();
	return 0;
}