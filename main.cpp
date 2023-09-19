// Программа имеет ограничения: 3 пользователя но можно расширить
// так же расчитана на 100 сообщений

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


Logger writeFile(true);//создаем обьект записи файла
Logger readFile(false);//создаем обьект чтения файла
std::mutex mtxAll;//семафор потоков для синхронизации


//----------------------------------------------------------------
void writer(std::mutex& mtxA)//создаем поток для записи сообщения 
{
	std::string text;
	while (1)
	{
		if (flagWrite)
		{
			mtxA.lock();//разблокируем мьтекс щабираем поток
			writeFile.writeFile(globalTextToFile);
			flagWrite = false;
			flagRead = true;
			mtxA.unlock();//разблокируем мьютекс освобождаем поток
		}
		Sleep(500);
	}
}

//-----------------------------------------------------------------
void reader(std::mutex& mtxB)//создаем поток для чтения сообщения
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
	countObject = 0; // количество созданых обьектов или количество элементов в массиве
	countMessage = 0;//порядковый номер сообщения
	char* op;//запись символа операции
	std::string tempOP;
	sizeMap=createNullMap();//создание пустых сообщений в Map
	Log_pass* lgPass = new Log_pass; // Создаем обьект логина и пароля
//----------------------------------------------------------------------
	while (true) {
		//	std::cout << "Press key:'q'-quit, 'n'-create , 'd'-delete , 'e'-enter , 's'- show\n";
		std::cout << "Выберите опцию:'в'-Выход, 'н'-Создать нового пользователя , 'л'-Войти под лог. и паролем\n";
		std::cout << ">> ";
		std::cin >> tempOP;
		if (tempOP.size() == 1) {
			std::vector<char>chars(tempOP.begin(), tempOP.end());//преобразователь string ->char
			chars.push_back('\0');
			op = &chars[0];

			if (*op == 'в') {
				exit(0);
			}
			switch (*op) {
			case'н':
				sizePassLog = lgPass->addLogPass();
				lgPass->printLogPass();
				break;
			case'л':
				if (lgPass->enterLogPass())
					lgPass->showMessages();
				break;
			defalt:
				std::cout << "Неправильно выбрали букву";
			}
		}
	}
//----------------------------------------------------------------------	
	w1.join();//ждем поток
	r1.join();
	
	return 0;
}
