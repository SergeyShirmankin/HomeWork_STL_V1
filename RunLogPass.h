#pragma once
const int maxPerson = 3;//������������ ���������� ����� ������� ����� �������� � ����
static int countObject;
static int curSesion;//�������� ������
const int maxMess = 100;//������������ ���������� ��������� � ����
//int createLogPass(int sizePass);
void deleteLogPass();
bool enterLogPass();
void showLogPass();
int showMessages();
void deleteMess();
int createNullMap();