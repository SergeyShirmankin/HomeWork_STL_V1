#pragma once
#include <thread>
#include <iostream>
#include <fstream>
#include <string> 

class Logger
{
public:
	Logger(bool status);//при 1 создаем файл для записи, при 0 создем файл для чтения
	void writeFile(const std::string& msg);//запись данных в файл
	~Logger();
	void readFile(); //чтение данных из файла
public:
	std::ofstream out;
	std::ifstream in;
};
