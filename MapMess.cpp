#include "MapMess.h"
#include <iostream>
using namespace std;
MapMess::MapMess() 
{
	int a = 0;
}
int MapMess::AddScore(int idNumber, Messages score)
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
//void MapMess::AddScore(int idNumber, Messages score)
//{
//	auto it = _messages.find(idNumber);
//	if (it != _messages.end())
//	{
//		score = it->second;
//	}
//	else
//		_messages.emplace(idNumber, score);
//}
//
//

//void MapMess::DeleteScore(const string & name)
//{
//	auto it = _table.find(name);
//	if (it != _table.end())
//		_table.erase(it);
//}
//
//
//void MapMess::PrintScore(const string & name)
//{
//	auto it = _table.find(name);
//	cout << name << " " << it->second << endl;
//}
