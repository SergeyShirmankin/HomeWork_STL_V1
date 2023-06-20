#include "LogPass.h"
#include "MapMess.h"
#include "RunLogPass.h"
std::string currUser = "Null";
int resultCompFindUser;
int resultCompFindReceiver;
int convIngTempRec;
std::string tempReceiver;
std::string tempMessage;
std::string tempCin;
std::string Null = "Null";

Log_pass::Log_pass()//конструктор по умолчанию
{
	int a = 1;
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


void Log_pass::printLogPass()
{
	cout << "----------------------------print -----------------------" << endl;
	for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
		cout << (*it).first << " : " << (*it).second << endl;
	cout << endl;
}

int Log_pass::addLogPass()
{
	std::cout << " Введите логин нового пользователя: " << std::endl;
	std::cout << ">> ";
	std::cin >> login;//Вводим новый логин				  
	auto it = _log_pass.find(login);
	if (it != _log_pass.end())
	{
		std::cout << std::endl;
		std::cout << ">> Логин уже есть. Выберите другой" << std::endl;
	}
	else
	{
		std::cout << "Введите нового пароля: " << std::endl;
		std::cout << ">> ";
		std::cin >> password;
		_log_pass.emplace(login, password);
	}
	       	countObject++;
	return _log_pass.size();
}


bool Log_pass::enterLogPass()
{
	bool resultCompare = false;
	std::string _password;
	std::string _login;
	std::cout << " Введите логин нового пользователя: " << std::endl;
	std::cout << ">> ";
	std::cin >> _login;//Вводим новый логин
	std::cout << "Введите пароль\n";
	std::cout << ">> ";
	std::cin >> _password;
	int i = -1;
	printLogPass();
	for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
	{ 
	    i++;
		if (!(_login.compare(it->first))&& !(_password.compare(it->first)))
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


int Log_pass::showMessages()
{
	char key;
	int countUsers = -1;
	system("cls");
	while (true)
	{
		std::cout << "\nДля выхода нажмите клавишу 'в' для продолжения нажмите любую кл и ent";
		std::cout << "\n>> ";
		std::cin >> key;
		if (key == 'в') { break; }
		else {
			system("cls");
			std::cout << "Online users: ";
			for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
			{
				countUsers ++;
				cout << it->first << "[" << countUsers << "], " ;
			}
			cout << endl;			
					std::cout << "\nStart Session[" << curSesion << "]:\n";
					std::cout << "Hello " << currUser << "\n";		
		}
	}
	return 0;
}

void Log_pass::findMess() {
	//		// Поиск и вывод строк
			for (int i = 0; i < maxMess; ++i)
			{
				if (!currUser.compare(_messages[i].getOwn()))
				{
	    			std::cout << "\n" << _messages[i].getOwn() << "->" << _messages[i].getReceiver();
					std::cout << ">> " << _messages[i].getMessage();
				}
			    if (currUser.compare(_messages[i].getReceiver()))
				{
					std::cout << "\n" << _messages[i].getOwn() << "->" << _messages[i].getReceiver();
					std::cout << ">> " << _messages[i].getMessage();
				}
			}
}
int Log_pass::writeMess() 
{
	//		std::cout << "\nВыберите  получателя сообщения";
	//    	std::cout << "\n>> ";
	//    	std::cin >> tempReceiver;//Выбираем получателя
	////		Поиск  нулeвой строки и запись в него строки 
	//    	if (tempReceiver.size() == 0) { return 1; }//защита от пустой строки
	////		try
	////		{
	////			convIngTempRec = stoi(tempReceiver);//проверка на правильность приведения string в int
	////    	}
	////		catch (std::invalid_argument e) {
	////			std::cout << "\nВнимание, некорекный ввод\n";
 ////   			return 1;
 ////    		}

	//		for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
	//		{

	//			if (!(_login.compare(it->first)) && !(_password.compare(it->first)))
	//			{
	//				curSesion = i;
	//				currUser = it->first;
	//				resultCompare = true;
	//				return true;
	//			}
	//		}
	////		if (0 <= convIngTempRec && convIngTempRec <= maxPerson) {
	//			for (int i = 0; i < maxMess; ++i)
	//		{
	//			if (!Null.compare(_messages[i].getOwn()))
	//				
	//			{
	////					_messages[i].setOwn(_messages[curSesion].getLog());
	////					messagesPtr[i]->setReceiver(personsPtr[convIngTempRec]->getLog());
	////					std::cout << "\n" << messagesPtr[i]->getOwn() << "->" << messagesPtr[i]->getReceiver();
	////					std::cout << ">> ";
	////					std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
	////					tempMessage = tempCin + " " + tempMessage;
	////					if (tempMessage.size() == 0) { break; }
	////					messagesPtr[i]->setMessage(tempMessage);
	////					break;

	////				}
	////			}
	//		}
	return 0;
}
//using namespace std;
//
//struct Test {
//	string t;
//	int i;
//};
//---------------------------------------------
//int _tmain(int argc, _TCHAR* argv[])
//{
//	system("chcp 1251");
//
//	int test;
//	vector<Test*> data;
//	map<int, Test*> itag; // !!!
//	for (int i = 0; i < 10; i++) {
//
//		Test* test = new Test;
//		test->i = i;
//		test->t = 'a' + i;
//
//		data.push_back(test);
//		itag[i] = test;
//	}
//
//	for (int i = 0; i < 10; i++) cout << itag[i]->t << endl;// Test
//	// удаление  и очистка
//	for (int i = 0; i < 10; i++) delete data[i];
//	data.clear();
//	itag.clear();
//
//	system("pause");
//	return 0;
//}
	//int resultCompFindUser;
	//int resultCompFindReceiver;
	//int convIngTempRec;
	//std::string tempReceiver;
	//std::string tempMessage;
	//std::string tempCin;
	//char key;
	//system("cls");
	//while (true)
	//{
	//	std::cout << "\nДля выхода нажмите клавишу 'в' для продолжения нажмите любую кл и ent";
	//	std::cout << "\n>> ";
	//	std::cin >> key;
	//	if (key == 'в') { break; }
	//	else {
	//		system("cls");
	//		std::cout << "Online users: ";
	//		for (int i = 0; i < countObject; ++i)
	//		{
	//			std::cout << personsPtr[i]->getLog() << "[" << i << "], ";
	//		}
	//		std::cout << "\nStart Session[" << curSesion << "]:\n";
	//		std::cout << "Hello " << personsPtr[curSesion]->getLog() << "\n";
	//		currUser = personsPtr[curSesion]->getLog();

	//		// Поиск и вывод строк
	//		for (int i = 0; i < maxMess; ++i)
	//		{
	//			resultCompFindUser = currUser.compare(messagesPtr[i]->getOwn());
	//			if (resultCompFindUser == 0)
	//			{
	//				std::cout << "\n" << messagesPtr[i]->getOwn() << "->" << messagesPtr[i]->getReceiver();
	//				std::cout << ">> " << messagesPtr[i]->getMessage();
	//			}
	//			resultCompFindReceiver = currUser.compare(messagesPtr[i]->getReceiver());
	//			if (resultCompFindReceiver == 0)
	//			{
	//				std::cout << "\n" << messagesPtr[i]->getOwn() << "->" << messagesPtr[i]->getReceiver();
	//				std::cout << ">> " << messagesPtr[i]->getMessage();
	//			}
	//		}
	//		std::cout << "\nВыберите цифру получателя сообщения, для всеобщей рассылки выберите[9] ";
	//		std::cout << "\n>> ";
	//		std::cin >> tempReceiver;//Выбираем получателя
	//		//Поиск  нулeвой строки и запись в него строки 
	//		if (tempReceiver.size() == 0) { break; }//защита от пустой строки
	//		try
	//		{
	//			convIngTempRec = stoi(tempReceiver);//проверка на правильность приведения string в int
	//		}
	//		catch (std::invalid_argument e) {
	//			std::cout << "\nВнимание, некорекный ввод\n";
	//			return 1;
	//		}
	//		if (0 <= convIngTempRec && convIngTempRec <= maxPerson) {
	//			for (int i = 0; i < maxMess; ++i)
	//			{
	//				if (messagesPtr[i]->getOwn() == Null)
	//				{
	//					messagesPtr[i]->setOwn(personsPtr[curSesion]->getLog());
	//					messagesPtr[i]->setReceiver(personsPtr[convIngTempRec]->getLog());
	//					std::cout << "\n" << messagesPtr[i]->getOwn() << "->" << messagesPtr[i]->getReceiver();
	//					std::cout << ">> ";
	//					std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
	//					tempMessage = tempCin + " " + tempMessage;
	//					if (tempMessage.size() == 0) { break; }
	//					messagesPtr[i]->setMessage(tempMessage);
	//					break;

	//				}
	//			}
	//		}
	//		//запись для всеъх пользователей
	//		if (convIngTempRec == 9) {
	//			for (int iMess = 0; iMess < maxMess; ++iMess)
	//			{
	//				if (messagesPtr[iMess]->getOwn() == Null)
	//				{
	//					std::cout << "\nВведите сообщение:\n";
	//					std::cout << ">> ";
	//					std::getline(std::cin >> tempCin, tempMessage);//забираем всю строку
	//					tempMessage = tempCin + " " + tempMessage;
	//					if (tempMessage.size() == 0) { break; }
	//					for (int i = 0; i < countObject; ++i)
	//					{
	//						if (curSesion != i)
	//						{
	//							messagesPtr[iMess]->setMessage(tempMessage);
	//							messagesPtr[iMess]->setOwn(personsPtr[curSesion]->getLog());
	//							messagesPtr[iMess]->setReceiver(personsPtr[i]->getLog());
	//							std::cout << "\n" << messagesPtr[iMess]->getOwn() << "->" << messagesPtr[iMess]->getReceiver() << ": " << messagesPtr[iMess]->getMessage();
	//							if (iMess < maxMess) { ++iMess; }
	//						}
	//					}
	//				}
	//				if (messagesPtr[iMess]->getOwn() == Null) { break; }
	//			}
	//		}
	//	}
	//}









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
