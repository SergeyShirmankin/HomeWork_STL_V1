#pragma once
#include <iostream>
#include <string>
#include <map>
//const int maxMess = 100;
using namespace std;
class Log_pass {
public:
	Log_pass();//����������� �� ���������
	std::string getLog();//�������
	std::string getPass();
	int addLogPass();//�������� ����� � ������
	Log_pass* getPtrObject();
	bool enterLogPass();
	int showMessages();
private:
	Log_pass* ptrObject;// ��������� �� ������
	std::string login;//���� ������
	std::string password;// ���� ������
	map<string,string> _log_pass;
};
