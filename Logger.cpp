#include "Logger.h"
#include <string> 

Logger::Logger(bool status)//создаем обьект который открывает файл либо для чтения либо для записи
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

Logger::~Logger()// при разрушении обьекта закрываем файлы 
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
		std::cout << "\nИнформация в файле :" << std::endl;
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
}
