#include "Messages.h"

Messages::Messages()
{
//	++countMessage;//”величиваем номер сообщени€ дл€ записи в его поле
//	this->number = countMessage;
	this->own = "Null";
	this->receiver = "Null";
	ptrMess = this;
}

//int Messages::getNumber()
//{
//	return this->number;
//}

std::string Messages::getOwn()
{
	return this->own;
}

std::string Messages::getReceiver()
{
	return this->receiver;
}

std::string Messages::getMessage()
{
	return this->message;
}

Messages* Messages::getPtrMess()
{
	return this->ptrMess;
}

void Messages::setOwn(std::string  _own)
{
	this->own = _own;
}

void Messages::setReceiver(std::string _received)
{
	this->receiver = _received;
}

void Messages::setMessage(std::string _message)
{
	this->message = _message;
}
