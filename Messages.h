#pragma once
#include <iostream>
#include <map>
using namespace std;
static int countMessage;

class Messages {
public:
	Messages();
//	int getNumber();
	std::string getOwn();
	std::string getReceiver();
	std::string getMessage();
	Messages* getPtrMess();
	void setOwn(std::string);
	void setReceiver(std::string);
	void setMessage(std::string);
private:
//	int number;//номер сообщения
	std::string own;//владелец сообщения
	std::string receiver;//получатель сообщения
	std::string message;//сообщения
	Messages* ptrMess;//указатель на сообщение;
};
