// ��������� ����� �����������: 3 ������������ �� ����� ���������
// ��� �� ��������� �� 100 ���������

#include <iostream>
#include <map>
#include <Windows.h>
#include "RunLogPass.h"
#include "MapMess.h"
#include "LogPass.h"
#include <vector>

using namespace std;

int main() 
{
	int sizeMap;
	int sizePassLog = 0;
	countObject = 0; // ���������� �������� �������� ��� ���������� ��������� � �������
	countMessage = 0;//���������� ����� ���������
	char* op;//������ ������� ��������
	std::string tempOP;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	sizeMap=createNullMap();//�������� ������ ��������� � Map
	Log_pass* lgPass = new Log_pass; // ������� ������ ������ � ������
//----------------------------------------------------------------------
	while (true) {
		//	std::cout << "Press key:'q'-quit, 'n'-create , 'd'-delete , 'e'-enter , 's'- show\n";
		std::cout << "�������� �����:'�'-�����, '�'-������� ������ ������������ , '�'-����� ��� ���. � �������\n";
		std::cout << ">> ";
		std::cin >> tempOP;
		if (tempOP.size() == 1) {
			std::vector<char>chars(tempOP.begin(), tempOP.end());//��������������� string ->char
			chars.push_back('\0');
			op = &chars[0];

			if (*op == '�') {
				exit(0);
			}
			switch (*op) {
			case'�':
				sizePassLog = lgPass->addLogPass();
				lgPass->printLogPass();
				break;
			case'�':
				if (lgPass->enterLogPass())
					lgPass->showMessages();
				break;
			defalt:
				std::cout << "����������� ������� �����";
			}
		}
	}
//----------------------------------------------------------------------	
	return 0;
}
