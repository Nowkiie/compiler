#include <iostream>
#include <string>
#include "Parser.h"

int main()
{
	setlocale(LC_ALL, "rus");
	string code = R"( 
���������� ������� � 8 �
���������� ������� � 3 �



�������
�
	��������(�������, ��);
	��������(�������, ���);

	�1 = ������(�������);
	���� (�1 == �����)
	�
	  �������(�������, �����);
	�
	�����
	�
		�������(�������, ����);
	�	
	
�

)";
	
	cout << code << '\n';
	
	parser pars(code);
	pars.parse();
	return 0;
}