#pragma once
#include <iostream>
#include <map>
using namespace std;
static int countMessage;

class Messages {
public:
	Messages();
	std::string getOwn();
	std::string getReceiver();
	std::string getMessage();
	Messages* getPtrMess();
	void setOwn(std::string);
	void setReceiver(std::string);
	void setMessage(std::string);
	int resultCompFindUser;
private:
	std::string own;//�������� ���������
	std::string receiver;//���������� ���������
	std::string message;//���������
	Messages* ptrMess;//��������� �� ���������;

};
