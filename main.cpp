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
	sizeMap=createNullMap();//создание пустых сообщений в Map
	Log_pass* lgPass = new Log_pass;  //вышел за границы 
	sizePassLog = lgPass->addLogPass();//создание новошо пользователя
	sizePassLog = lgPass->addLogPass();//создание новошо пользователя
	if(lgPass->enterLogPass())
		lgPass->showMessages();
	
	return 0;
}
