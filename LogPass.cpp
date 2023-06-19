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

Log_pass::Log_pass()//����������� �� ���������
{
	int a = 1;
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
//	for (int i = 0; i < countObject; ++i)
	for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
	{ 
	    i++;
		//int resultLog = _login.compare(personsPtr[i]->getLog());
//		int resultPass = _password.compare(personsPtr[i]->getPass());
		if (!(_login.compare(it->first))&& !(_password.compare(it->first)))
//		if (resultLog == 0 && resultPass == 0)
       	{
 			curSesion = i;
    		resultCompare = true;
			return true;
    	}
	}
		return false;	
}

//bool enterLogPass()
//{
//	bool resultCompare = false;
//	std::string _password;
//	std::string _login;
//	std::cout << "������� �����\n";
//	std::cout << ">> ";
//	std::cin >> _login;
//	std::cout << "������� ������\n";
//	std::cout << ">> ";
//	std::cin >> _password;
//	for (int i = 0; i < countObject; ++i)
//	{
//		int resultLog = _login.compare(personsPtr[i]->getLog());
//		int resultPass = _password.compare(personsPtr[i]->getPass());
//		if (resultLog == 0 && resultPass == 0)
//		{
//			curSesion = i;
//			resultCompare = true;
//			return true;
//		}
//	}
//	std::cout << "Not access.\n ";
//	return false;
//
//

int Log_pass::showMessages()
{
	char key;
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
			int countUsers = 0;
			for (auto it = _log_pass.begin(); it != _log_pass.end(); ++it)
			{
				countUsers ++;
				currUser  =  it->first;
			}
			cout << countUsers << endl;
			
			std::cout << "Hello " << countUsers << "\n";

		}
	}
	return 0;
}
void MapMess::findMess() {
	//		// ����� � ����� �����
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
int MapMess::writeMess() 
{
	//		std::cout << "\n�������� ����� ���������� ���������, ��� �������� �������� ��������[9] ";
	//    	std::cout << "\n>> ";
	//		std::cin >> tempReceiver;//�������� ����������
	////		�����  ���e��� ������ � ������ � ���� ������ 
	//     	if (tempReceiver.size() == 0) { return 1; }//������ �� ������ ������
	//		try
	//		{
	//			convIngTempRec = stoi(tempReceiver);//�������� �� ������������ ���������� string � int
	//    	}
	//		catch (std::invalid_argument e) {
	//			std::cout << "\n��������, ���������� ����\n";
 //   			return 1;
 //    		}
	//		if (0 <= convIngTempRec && convIngTempRec <= maxPerson) {
	//			for (int i = 0; i < maxMess; ++i)
	//			{
	//				if (!Null.compare(_messages[i].getOwn()))
	//					
	//				{
	//					_messages[i].setOwn(_messages[curSesion].getLog());
	//					messagesPtr[i]->setReceiver(personsPtr[convIngTempRec]->getLog());
	//					std::cout << "\n" << messagesPtr[i]->getOwn() << "->" << messagesPtr[i]->getReceiver();
	//					std::cout << ">> ";
	//					std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
	//					tempMessage = tempCin + " " + tempMessage;
	//					if (tempMessage.size() == 0) { break; }
	//					messagesPtr[i]->setMessage(tempMessage);
	//					break;

	//				}
	//			}
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
//	// ��������  � �������
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
	//	std::cout << "\n��� ������ ������� ������� '�' ��� ����������� ������� ����� �� � ent";
	//	std::cout << "\n>> ";
	//	std::cin >> key;
	//	if (key == '�') { break; }
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

	//		// ����� � ����� �����
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
	//		std::cout << "\n�������� ����� ���������� ���������, ��� �������� �������� ��������[9] ";
	//		std::cout << "\n>> ";
	//		std::cin >> tempReceiver;//�������� ����������
	//		//�����  ���e��� ������ � ������ � ���� ������ 
	//		if (tempReceiver.size() == 0) { break; }//������ �� ������ ������
	//		try
	//		{
	//			convIngTempRec = stoi(tempReceiver);//�������� �� ������������ ���������� string � int
	//		}
	//		catch (std::invalid_argument e) {
	//			std::cout << "\n��������, ���������� ����\n";
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
	//					std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
	//					tempMessage = tempCin + " " + tempMessage;
	//					if (tempMessage.size() == 0) { break; }
	//					messagesPtr[i]->setMessage(tempMessage);
	//					break;

	//				}
	//			}
	//		}
	//		//������ ��� ����� �������������
	//		if (convIngTempRec == 9) {
	//			for (int iMess = 0; iMess < maxMess; ++iMess)
	//			{
	//				if (messagesPtr[iMess]->getOwn() == Null)
	//				{
	//					std::cout << "\n������� ���������:\n";
	//					std::cout << ">> ";
	//					std::getline(std::cin >> tempCin, tempMessage);//�������� ��� ������
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
