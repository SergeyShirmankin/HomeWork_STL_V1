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

