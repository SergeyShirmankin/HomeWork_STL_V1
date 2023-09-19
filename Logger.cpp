#include "Logger.h"
#include <string> 

Logger::Logger(bool status)//������� ������ ������� ��������� ���� ���� ��� ������ ���� ��� ������
{
	if (status)
		out.open("Log.txt", std::ios::app);
	else
		in.open("Log.txt");
}

void Logger::writeFile(const std::string& msg)
{
	if (out.is_open())
	{
		out << msg << std::endl;
	}
}

Logger::~Logger()// ��� ���������� ������� ��������� ����� 
{
	if (out.is_open())
	out.close();
	if (in.is_open())
	in.close();
}

void Logger::readFile()
{
	std::string line;
	if (in.is_open())
	{
		std::cout << "\n���������� � ����� :" << std::endl;
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
}
