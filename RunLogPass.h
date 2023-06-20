#pragma once
const int maxPerson = 3;//максимальное количество людей которое можно работать в чате
static int countObject;
static int curSesion;//активная сессия
const int maxMess = 100;//максимальное количество сообщений в чате
void deleteLogPass();
bool enterLogPass();
void showLogPass();
int showMessages();
void deleteMess();
int createNullMap();