#include "RunLogPass.h"
#include "Messages.h"
#include "MapMess.h"
#include "LogPass.h"
int createNullMap()// �������� ������ ���������
{
	int size;
	MapMess* pSt = new MapMess;
	MapMess& st = *pSt;
	for (int i = 0; i < maxMess; ++i) {
			Messages* pMess = new Messages;
			Messages& mess = *pMess; //�������������� ��������� � ������
			size=st.AddScore(i, mess);
	}
	return size;
}

