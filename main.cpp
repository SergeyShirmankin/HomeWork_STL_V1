#include <iostream>
#include <map>
#include <Windows.h>
#include "RunLogPass.h"
#include "MapMess.h"
#include "LogPass.h"

using namespace std;

int main() 
{
	int sizeMap;
	int sizePassLog = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	sizeMap=createNullMap();//�������� ������ ��������� � Map
	Log_pass* lgPass = new Log_pass;  //����� �� ������� 
	sizePassLog = lgPass->addLogPass();//�������� ������ ������������
	sizePassLog = lgPass->addLogPass();//�������� ������ ������������
	lgPass->enterLogPass();
	lgPass->enterLogPass();
	lgPass->enterLogPass();
	//if(lgPass->enterLogPass())
	//	showMessages();
	return 0;
}
