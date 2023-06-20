#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Messages.h"
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
	void showMessages();
	void printLogPass();
//----------------------------------------------------------------------
	int AddScore(int idNumber, Messages score);
	void findMess();
	int writeMess();
//-----------------------------------------------------------------------
private:
	Log_pass* ptrObject;// ��������� �� ������
	std::string login;//���� ������
	std::string password;// ���� ������
	map<string,string> _log_pass;
	map<int, Messages> _messages;
};
