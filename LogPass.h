#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Log_pass {
public:
	Log_pass();//����������� �� ���������
	std::string getLog();//�������
	std::string getPass();
	int addLogPass();//�������� ����� � ������
	Log_pass* getPtrObject();
	bool enterLogPass();

private:
	Log_pass* ptrObject;// ��������� �� ������
	std::string login;//���� ������
	std::string password;// ���� ������
	map<string,string> _log_pass;
};
