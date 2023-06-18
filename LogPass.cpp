#include "LogPass.h"

Log_pass::Log_pass()//����������� �� ���������
{
	int a = 1;
}
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
	return _log_pass.size();
}

bool Log_pass::enterLogPass()
{
	bool resultCompare = false;
	std::string _password;
	std::string _login;
	std::cout << " ������� ����� ������ ������������: " << std::endl;
	std::cout << ">> ";
	std::cin >> _login;//������ ����� �����
	auto it = _log_pass.find(_login);
	if (it != _log_pass.end())
	{
		std::cout << "������� ������\n";
        std::cout << ">> ";
        std::cin >> _password;
		if (_password.compare(it->second) == 0)//�������� ������
			return true;
	}
		return false;	
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
