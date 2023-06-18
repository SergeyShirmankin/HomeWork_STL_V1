#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Log_pass {
public:
	Log_pass();//Конструктор по умолчанию
	std::string getLog();//геттеры
	std::string getPass();
	int addLogPass();//добавить логин и пароль
	Log_pass* getPtrObject();
	bool enterLogPass();

private:
	Log_pass* ptrObject;// Указатель на обьект
	std::string login;//поле логина
	std::string password;// поле пароля
	map<string,string> _log_pass;
};
