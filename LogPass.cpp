#include "LogPass.h"
#include "MapMess.h"
#include "RunLogPass.h"
#include <iostream>
#include "main.h"
std::string currUser = "Null";
int resultCompFindUser;
int resultCompFindReceiver;
int convIngTempRec;
std::string tempReceiver;
std::string tempMessage;
std::string tempCin;
std::string Null = "Null";


Log_pass::Log_pass()//����������� �� ���������
{
	int a = 1; // ������ ��������, ����� �� ���� ������
}
Log_pass::~Log_pass()
{
	int b = 2;
}

int Log_pass::AddScore(int idNumber, Messages score)
{
	auto it = _messages.find(idNumber);
	if (it != _messages.end())
	{
		score = it->second;
	}
	else
		_messages.emplace(idNumber, score);
	return _messages.size();
}
//---------------------------------------------------------------------------------------
//------------------------ ������ � ���� ������ ���������--------------------------------
//---------------------------------------------------------------------------------------
void Log_pass::printLogPass()
{
	globalTextToFile = "";
	cout << "----------------------------print -----------------------" << endl;
	for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
	{
	    flagWrite = true;//������ ������� ������ � ����
		globalTextToFile = (*it).first;
		globalTextToFile = globalTextToFile + " : ";
		globalTextToFile = globalTextToFile + (*it).second;
		cout << (*it).first << " : " << (*it).second << endl;
		//bool flagWrite = true ;//������ ������� ������ � ����
	}
	cout << endl;
}
//-------------------------- �������� ������ � ������--------------------------------------
int Log_pass::addLogPass()
{
	std::cout << " ������� ����� ������ ������������: " << std::endl;
	std::cout << ">> ";
	std::cin >> login;//������ ����� �����				  
	auto it = _log_pass.find(login);
	if (it != _log_pass.end())
	{
		std::cout << std::endl;
		std::cout << ">> ����� ��� ����. �������� ������" << std::endl;
	}
	else
	{
		std::cout << "������� ������ ������: " << std::endl;
		std::cout << ">> ";
		std::cin >> password;
		_log_pass.emplace(login, password);
	}
	       	countObject++;
	return _log_pass.size();
}

// ������� ������������
bool Log_pass::enterLogPass()
{
	bool resultCompare = false;
	std::string _password;
	std::string _login;
	std::cout << " ������� ����� ������ ������������: " << std::endl;
	std::cout << ">> ";
	std::cin >> _login;//������ ����� �����
	std::cout << "������� ������\n";
	std::cout << ">> ";
	std::cin >> _password;
	int i = -1;
	printLogPass();
	for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
	{ 
	    i++;
		if (!(_login.compare(it->first))&& !(_password.compare(it->second)))
       	{
 			curSesion = i;
			currUser = it->first;
    		resultCompare = true;
			return true;
    	}
	}
		return false;
		std::cout << "Not access.\n ";
}

// �������� ������� ��� ������ � �����������
void Log_pass::showMessages()
{
	char key;
	int countUsers = -1;
	system("cls");
	while (true)
	{
		std::cout << "\n��� ������ ������� ������� '�' ��� ����������� ������� ����� �� � ent";
		std::cout << "\n>> ";
		std::cin >> key;
		if (key == '�') { break; }
		else {
			system("cls");
			std::cout << "Online users: ";
			for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
			{
				countUsers++;
				cout << it->first << "[" << countUsers << "], ";
			}
			cout << endl;
			std::cout << "\nStart Session[" << curSesion << "]:\n";
			std::cout << "Hello " << currUser << "\n";
			//		// ����� � ����� �����
			for (int i = 0; i < maxMess; ++i)
			{
				if (!currUser.compare(_messages[i].getOwn()))
				{
					std::cout << "\n" << _messages[i].getOwn() << "->" << _messages[i].getReceiver();
					std::cout << ">> " << _messages[i].getMessage();
				}
				if (!currUser.compare(_messages[i].getReceiver()))
				{
					std::cout << "\n" << _messages[i].getOwn() << "->" << _messages[i].getReceiver();
					std::cout << ">> " << _messages[i].getMessage();
				}
			}
			std::cout << "\n��������  ���������� ���������";
			std::cout << "\n>> ";
			std::cin >> tempReceiver;//�������� ����������
			if (tempReceiver.size() == 0) { return; }//������ �� ������ ������
			for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)//�������� ���������� ���������
			{
				if (!(tempReceiver.compare(it->first)))
				{
					for (int i = 0; i < maxMess; ++i)
					{
						if (!Null.compare(_messages[i].getOwn()))
						{
							_messages[i].setOwn(currUser);
							_messages[i].setReceiver(tempReceiver);
							cout << "\n" << _messages[i].getOwn() << "->" << _messages[i].getReceiver();
							std::cout << ">> ";
							std::getline(cin >> tempCin, tempMessage);//�������� ��� ������
							tempMessage = tempCin + " " + tempMessage;
							if (tempMessage.size() == 0) { break; }
							_messages[i].setMessage(tempMessage);
							break;
						}
					}
				}
			}
		}
	}
}


std::string Log_pass::getLog()
{
	return login;
}

std::string Log_pass::getPass()
{
	return password;
}

Log_pass* Log_pass::getPtrObject()
{
	return ptrObject;
}
