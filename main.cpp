// ��������� ����� �����������: 3 ������������ �� ����� ���������
// ��� �� ��������� �� 100 ���������

#include <iostream>
#include <map>
#include <Windows.h>
#include "RunLogPass.h"
#include "MapMess.h"
#include "LogPass.h"
#include <vector>
#include "Logger.h"
#include <mutex>
#include <thread>
#include "main.h"

//-----------------------------------------------------------------
using namespace std;
bool flagWrite = false;
bool flagRead = false;
std::string globalTextToFile = "";


Logger writeFile(true);//������� ������ ������ �����
Logger readFile(false);//������� ������ ������ �����
std::mutex mtxAll;//������� ������� ��� �������������


//----------------------------------------------------------------
void writer(std::mutex& mtxA)//������� ����� ��� ������ ��������� 
{
	std::string text;
	while (1)
	{
		if (flagWrite)
		{
			mtxA.lock();//������������ ������ �������� �����
			writeFile.writeFile(globalTextToFile);
			flagWrite = false;
			flagRead = true;
			mtxA.unlock();//������������ ������� ����������� �����
		}
		Sleep(500);
	}
}

//-----------------------------------------------------------------
void reader(std::mutex& mtxB)//������� ����� ��� ������ ���������
{
	std::string tempMess;
	while (1)
	{
		if (flagRead)
		{
			mtxB.lock();
			readFile.readFile();
			flagRead = false;
			mtxB.unlock();
			Sleep(500);
		}
	}
}

//-----------------------------------------------------------------
int main() 
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
//--------------------------------------------------------------------	
	std::thread w1(writer, ref(mtxAll));
	std::thread r1(reader, ref(mtxAll));
//--------------------------------------------------------------------
	int sizeMap;
	int sizePassLog = 0;
	countObject = 0; // ���������� �������� �������� ��� ���������� ��������� � �������
	countMessage = 0;//���������� ����� ���������
	char* op;//������ ������� ��������
	std::string tempOP;
	sizeMap=createNullMap();//�������� ������ ��������� � Map
	Log_pass* lgPass = new Log_pass; // ������� ������ ������ � ������
//----------------------------------------------------------------------
	while (true) {
		//	std::cout << "Press key:'q'-quit, 'n'-create , 'd'-delete , 'e'-enter , 's'- show\n";
		std::cout << "�������� �����:'�'-�����, '�'-������� ������ ������������ , '�'-����� ��� ���. � �������\n";
		std::cout << ">> ";
		std::cin >> tempOP;
		if (tempOP.size() == 1) {
			std::vector<char>chars(tempOP.begin(), tempOP.end());//��������������� string ->char
			chars.push_back('\0');
			op = &chars[0];

			if (*op == '�') {
				exit(0);
			}
			switch (*op) {
			case'�':
				sizePassLog = lgPass->addLogPass();
				lgPass->printLogPass();
				break;
			case'�':
				if (lgPass->enterLogPass())
					lgPass->showMessages();
				break;
			defalt:
				std::cout << "����������� ������� �����";
			}
		}
	}
//----------------------------------------------------------------------	
	w1.join();//���� �����
	r1.join();
	
	return 0;
}
