#pragma once
#include <thread>
#include <iostream>
#include <fstream>
#include <string> 

class Logger
{
public:
	Logger(bool status);//��� 1 ������� ���� ��� ������, ��� 0 ������ ���� ��� ������
	void writeFile(const std::string& msg);//������ ������ � ����
	~Logger();
	void readFile(); //������ ������ �� �����
public:
	std::ofstream out;
	std::ifstream in;
};
