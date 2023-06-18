#include "RunLogPass.h"
#include "Messages.h"
#include "MapMess.h"
#include "LogPass.h"
int createNullMap()// создание пустых сообщений
{
	int size;
	MapMess* pSt = new MapMess;
	MapMess& st = *pSt;
	for (int i = 0; i < maxMess; ++i) {
			Messages* pMess = new Messages;
			Messages& mess = *pMess; //преобразование указателя в ссылку
			size=st.AddScore(i, mess);
	}
	return size;
}
int showMessages()
{
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
  return 0;
}

