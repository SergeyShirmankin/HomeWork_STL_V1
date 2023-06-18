#pragma once
#include <iostream>
#include <string>
#include <map>
//const int maxMess = 100;
using namespace std;
class Log_pass {
public:
	Log_pass();//Конструктор по умолчанию
	std::string getLog();//геттеры
	std::string getPass();
	int addLogPass();//добавить логин и пароль
	Log_pass* getPtrObject();
	bool enterLogPass();
	int showMessages();
private:
	Log_pass* ptrObject;// Указатель на обьект
	std::string login;//поле логина
	std::string password;// поле пароля
	map<string,string> _log_pass;
};
